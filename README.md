# PyTorchで学習したモデルをTensorflow liteで推論する。

## environment

- [Miniforge](https://github.com/conda-forge/miniforge)  (Recommended)

```
$ pip install -r requirements.txt

$ git clone https://github.com/onnx/onnx-tensorflow.git
$ cd onnx-tensorflow
$ pip install -e .
```

## training


```
$ python train.py --save-onnx --save-model

$ onnx-tf convert -i mnist_cnn.onnx -i pbfile

$ tflite_convert --saved_model_dir=pbfile --output_file=mnist_cnn.tflite
```

以下の学習ずみモデルができます。

- mnist_cnn.pt
- mnist_cnn.onnx
- mnist_cnn.tflite

## testing

推論を実行しよう。

```
$ python test_pytorch.py

[[ 976    0    1    0    0    0    1    1    1    0]
 [   0 1134    0    1    0    0    0    0    0    0]
 [   1    1 1024    0    0    0    1    5    0    0]
 [   0    0    2 1004    0    3    0    0    1    0]
 [   0    0    0    0  977    0    1    0    1    3]
 [   0    0    0    3    0  888    1    0    0    0]
 [   4    2    0    0    1    3  947    0    1    0]
 [   0    2    5    1    0    0    0 1017    1    2]
 [   2    1    2    1    1    1    0    1  961    4]
 [   0    1    0    1    5    5    0    3    2  992]]
```

```
$ python test_tflite.py

[[ 972    1    0    0    0    2    2    1    2    0]
 [   0 1132    1    1    0    1    0    0    0    0]
 [   0    5 1013    4    1    0    1    6    2    0]
 [   0    0    1  995    0    6    0    7    1    0]
 [   1    0    1    0  967    0    3    0    2    8]
 [   1    0    0    3    0  883    3    1    1    0]
 [   2    4    0    0    1    8  942    0    1    0]
 [   0    2    9    0    0    1    0 1011    1    4]
 [   1    0    4    2    2    5    2    5  949    4]
 [   2    2    0    3    7    8    0    2    4  981]]
```

推論結果少し違いますね。

# NCHW形式 VS. NHWC形式 問題

ここでは PyTorch で学習した NCHW形式モデルをそのまま tflite に変換して、
推論時も NCHW形式で使ってる。

ということでで良いんですよね？？


# Reference

- https://github.com/pytorch/examples/tree/master/mnist ... main.py -> train.py 改造
- https://qiita.com/Teraterayuki/items/a1043d4bccfd2f24f1c3
- https://github.com/onnx/onnx-tensorflow.git
