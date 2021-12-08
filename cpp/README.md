# PyTorchで学習したモデルをTensorflow lite C++で推論する。

# build

```
$ pwd
somewere/MNIST_pytorch-tflite/cpp

$ git clone https://github.com/tensorflow/tensorflow.git tensorflow_src

$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . -j 4

```

# testing

データ、モデルの準備

```
$ pwd
somewere/MNIST_pytorch-tflite/cpp/build


$ python ../../convert_csv.py
$ cp ../../mnist_cnn.tflite .
```

Run

```
$ ./test 
INFO: Created TensorFlow Lite XNNPACK delegate for CPU.
 972    1    0    0    0    2    2    1    2    0 
   0 1132    1    1    0    1    0    0    0    0 
   0    5 1013    4    1    0    1    6    2    0 
   0    0    1  995    0    6    0    7    1    0 
   1    0    1    0  967    0    3    0    2    8 
   1    0    0    3    0  883    3    1    1    0 
   2    4    0    0    1    8  942    0    1    0 
   0    2    9    0    0    1    0 1011    1    4 
   1    0    4    2    2    5    2    5  949    4 
   2    2    0    3    7    8    0    2    4  981 
```

python版と推論結果は同一になってます。

# Reference

- [CMakeでTensorFlowLiteをビルドする](https://www.tensorflow.org/lite/guide/build_cmake)
- [TensorFlow Lite C++ minimal example](https://github.com/tensorflow/tensorflow/tree/master/tensorflow/lite/examples/minimal)
- https://github.com/iwatake2222/CNN_NumberDetector/blob/master/05_TensorflowLite_CPP/main_without_opencv.cpp を元にした。







