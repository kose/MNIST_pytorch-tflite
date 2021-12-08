# PyTorchで学習したモデルをTensorflow lite C++で推論する。

```
$ pwd
somewere/MNIST_pytorch-tflite/cpp

$ git clone https://github.com/tensorflow/tensorflow.git tensorflow_src

$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . -j 4



```


# Reference

- [CMakeでTensorFlowLiteをビルドする](https://www.tensorflow.org/lite/guide/build_cmake)
- [TensorFlow Lite C++ minimal example](https://github.com/tensorflow/tensorflow/tree/master/tensorflow/lite/examples/minimal)


- https://github.com/iwatake2222/CNN_NumberDetector/blob/master/05_TensorflowLite_CPP/main_without_opencv.cpp
