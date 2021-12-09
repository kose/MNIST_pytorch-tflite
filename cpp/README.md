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
 976    0    1    0    0    0    1    1    1    0 
   0 1134    0    1    0    0    0    0    0    0 
   1    1 1024    0    0    0    1    5    0    0 
   0    0    2 1004    0    3    0    0    1    0 
   0    0    0    0  977    0    1    0    1    3 
   0    0    0    3    0  888    1    0    0    0 
   4    2    0    0    1    3  947    0    1    0 
   0    2    5    1    0    0    0 1017    1    2 
   2    1    2    1    1    1    0    1  961    4 
   0    1    0    1    5    5    0    3    2  992 
```

同じ推論結果です。

# Reference

- [CMakeでTensorFlowLiteをビルドする](https://www.tensorflow.org/lite/guide/build_cmake)
- [TensorFlow Lite C++ minimal example](https://github.com/tensorflow/tensorflow/tree/master/tensorflow/lite/examples/minimal)
- https://github.com/iwatake2222/CNN_NumberDetector/blob/master/05_TensorflowLite_CPP/main_without_opencv.cpp を元にした。







