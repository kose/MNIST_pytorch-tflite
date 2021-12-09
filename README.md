# PyTorchで学習したモデルをTensorflow liteで推論する。

## environment

- Intel macOS (M1 ではonnx-tensorflowで失敗する。変換はできないけどPythoh, C++の推論は動く）
- [Miniforge](https://github.com/conda-forge/miniforge)  (Recommended)


## condaの場合

```
$ conda update --yes --all

$ conda install --yes numpy
$ conda install --yes scikit-learn

$ conda install --yes conda==4.10.3
$ conda install --yes tensorflow==2.6.2

$ conda install --yes conda==4.10.3
$ conda install --yes tensorflow-probability

$ conda install --yes pytorch
$ conda install --yes torchvision

$ git clone https://github.com/onnx/onnx-tensorflow.git
$ cd onnx-tensorflow
$ pip install -e .
```

## pipの場合
```
$ pip install -r requirements.txt

$ git clone https://github.com/onnx/onnx-tensorflow.git
$ cd onnx-tensorflow
$ pip install -e .
```

## training


```
$ python train.py --save-onnx --save-model

$ onnx-tf convert -i mnist_cnn.onnx -o pbfile

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

同じ推論結果です

# NCHW形式 VS. NHWC形式 問題

ここでは PyTorch で学習した NCHW形式モデルをそのまま tflite に変換して、
推論時も NCHW形式で使ってる。

ということでで良いんですよね？？


# Reference

- https://github.com/pytorch/examples/tree/master/mnist ... main.py -> train.py 改造
- https://qiita.com/Teraterayuki/items/a1043d4bccfd2f24f1c3
- https://github.com/onnx/onnx-tensorflow.git
