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

```

# Reference

- [CMakeでTensorFlowLiteをビルドする](https://www.tensorflow.org/lite/guide/build_cmake)
- [TensorFlow Lite C++ minimal example](https://github.com/tensorflow/tensorflow/tree/master/tensorflow/lite/examples/minimal)
- https://github.com/iwatake2222/CNN_NumberDetector/blob/master/05_TensorflowLite_CPP/main_without_opencv.cpp を元にした。







