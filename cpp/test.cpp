#include <iostream>

#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"
#include "tensorflow/lite/optional_debug_tools.h"

// #define DEBUG

#define MODEL_FILENAME "mnist_cnn.tflite"
#define DATA_CSV "mnist_test.csv"

#define TFLITE_MINIMAL_CHECK(x)                                 \
  if (!(x)) {                                                   \
    fprintf(stderr, "Error at %s:%d\n", __FILE__, __LINE__);    \
    exit(1);                                                    \
  }


int argmax(float probs[])
{
  int index = -1;
  float max = -1000;
  
  for (int i = 0; i < 10; i++) {
    if(max < probs[i]) {
      index = i;
      max = probs[i];
    }
  }

  TFLITE_MINIMAL_CHECK(0 <= index);
  
  return index;
}


std::vector<std::string> split(std::string& input, char delimiter)
{
  std::istringstream stream(input);
  std::string field;
  std::vector<std::string> result;
  
  while (getline(stream, field, delimiter)) {
    result.push_back(field);
  }
  return result;
}

int main()
{

  // tflite
  std::unique_ptr<tflite::FlatBufferModel> model = tflite::FlatBufferModel::BuildFromFile(MODEL_FILENAME);
  TFLITE_MINIMAL_CHECK(model != nullptr);

  // Build the interpreter
  tflite::ops::builtin::BuiltinOpResolver resolver;
  tflite::InterpreterBuilder builder(*model, resolver);
  std::unique_ptr<tflite::Interpreter> interpreter;
  builder(&interpreter);
  TFLITE_MINIMAL_CHECK(interpreter != nullptr);

  // Allocate tensor buffers.
  TFLITE_MINIMAL_CHECK(interpreter->AllocateTensors() == kTfLiteOk);
#ifdef DEBUG
  printf("=== Pre-invoke Interpreter State ===\n");
  tflite::PrintInterpreterState(interpreter.get());
#endif
    
  // Set data to input tensor
  float* input = interpreter->typed_input_tensor<float>(0);

  //
  // predict
  //
  float mnistdata[28 * 28];
  std::ifstream ifs(DATA_CSV);
  std::string line;
  int confusion_matrix[10][10] = {0};

  while(getline(ifs, line)) {

    std::vector<std::string> strvec = split(line, ',');

    int gt = stoi(strvec.at(0));
      
    for (int i = 1; i < strvec.size(); i++){
      mnistdata[i - 1] = stof(strvec.at(i));
    }

    //
    // inference
    //
    memcpy(input, mnistdata, sizeof(float) * 28 * 28);

    // Run inference
    TFLITE_MINIMAL_CHECK(interpreter->Invoke() == kTfLiteOk);
#ifdef DEBUG
    printf("\n\n=== Post-invoke Interpreter State ===\n");
    tflite::PrintInterpreterState(interpreter.get());
#endif
    
    // Get data from output tensor
    float* probs = interpreter->typed_output_tensor<float>(0);

    confusion_matrix[gt][argmax(probs)]++;
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%4d ", confusion_matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  return EXIT_SUCCESS;
}
