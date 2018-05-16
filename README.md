# Self-Organizing Map (SOM)

Fast, convenient and most complete C++ library using parallel computing based on OpenCL. The map has a hexagonal cells, which allows you to get the correct model view. All this makes it possible to use the library for high-level scientific works.

## Installation in Unix
Required Packages:
* `CMake 2.8` or higher
* `Git`

Required Dependencies:
* `OpenCL 1.1 ` or higher 
* `OpenCV 3` [optional] (for build lib som_view and examples)

These steps have been tested for macOS High Sierra 10.13.14 but should work with other unix systems as well.

```sh
1. $ cd ~/<my_working_directory>
2. $ git clone https://github.com/silkodenis/SOM.git
3. $ cd SOM
4. $ mkdir build
5. $ cd build
```

```sh
## to build som, view and examples
6. $ cmake -D CMAKE_INSTALL_PREFIX=/usr/local ../

## to build only lib som
6. $ cmake -D CMAKE_INSTALL_PREFIX=/usr/local ../som
```

```sh
7. $ make
8. $ sudo make install
```

### Notes
```sh
## to generate XCode project use:
6. $ cmake -G Xcode ../
```

```sh
## to build dynamic libs, use option: [-D BUILD_SHARED_LIBS=true], for example:
6. $ cmake -D BUILD_SHARED_LIBS=true -D CMAKE_INSTALL_PREFIX=/usr/local ../
```

## Examples
Here is a brief overview of the examples, the source code of which is attached.

**Simple training**

Hello world!

<p align="center">
  <img width="412" height="355" src="https://github.com/silkodenis/SOM/blob/readme_assets/examples/simple%20training/untrained_map.png?raw=true">
  
  <img width="412" height="355" src="https://github.com/silkodenis/SOM/blob/readme_assets/examples/simple%20training/trained_map.png?raw=true">
</p>

**Real-time training**

A simple example of how to train SOM and get a model view in real time.

<p align="center">
  <img width="568" height="649" src="https://github.com/silkodenis/SOM/blob/readme_assets/examples/real-time%20training/training_proccess.gif?raw=true">
</p>

**Regression**

A simple example of using SOM for regression analysis.

<p align="center">
  <img width="650" height="650" src="https://github.com/silkodenis/SOM/blob/readme_assets/examples/regression/training_process.gif?raw=true">
</p>

**Image as dataset**

An example of using an image as a data set. After receiving the clustered map from one image, we apply it to clustering another image.

<p align="center">
  <img width="800" height="531" src="https://github.com/silkodenis/SOM/blob/readme_assets/examples/image%20as%20dataset/image_as_dataset_target%20mat.png?raw=true">
</p>

<p align="center">
  <img width="363" height="347" src="https://github.com/silkodenis/SOM/blob/readme_assets/examples/image%20as%20dataset/image_as_dataset_training%20mat.png?raw=true">
  
  <img width="405" height="350" src="https://github.com/silkodenis/SOM/blob/readme_assets/examples/image%20as%20dataset/image_as_dataset_trained%20SOM.png?raw=true">
</p>

<p align="center">
  <img width="800" height="531" src="https://github.com/silkodenis/SOM/blob/readme_assets/examples/image%20as%20dataset/image_as_dataset_processed%20mat.png?raw=true">
</p>

**Single channel analysis**

A simple example of analyzing the channels of a trained map. 

<p align="center">
  <img width="435" height="376" src="https://lh5.googleusercontent.com/T_JvuqmKMOYPNOy1_B2TgHjYZNxCh5fFXkso3MsbDDHSNagEYSYVi3NzntdV4bHaPDV25ymxsbCHgw=w2880-h1632">
</p>

<p align="center">
  <img width="783" height="451" src="https://lh3.googleusercontent.com/_3eCDQEF13slSxcHLbIe4Sfrjn_dINqvfr9qagDDrByhto00vz7E4w0pcMg23H_LYDfE1qtTkdlh-w=w2880-h1632">
</p>


**Deep analysis**

This example demonstrates various interpretations model view of a trained map using the additional library som_view.

<p align="center">
  <img width="854" height="490" src="https://lh3.googleusercontent.com/31cQb6SXFv3B7pTwu6cEQKFzbaMeNGlq4_hWZ-oJCxjqme5mjOs7yGTtQK5YbZsJISPTY2p7wXQ9Sg=w2880-h1632">
</p>

<p align="center">
  <img width="854" height="490" src="https://lh5.googleusercontent.com/CszeKvdmXS3tUnnZUd2tVRzbnDsnnofqoKeHZOrC44EpXCtLkHEsVbLRQcWQXaet8tTGsGksm0Ouaw=w2880-h1632">
</p>

<p align="center">
  <img width="854" height="490" src="https://lh6.googleusercontent.com/imUUfF_u5yCeSLZJcw231XSGwzO0cB4iA6JPAl_EY9QFoKwSNToSPD4_LDlN1H2YHJb8b0D2hH3jMQ=w2880-h1632">
</p>

<p align="center">
  <img width="854" height="490" src="https://lh6.googleusercontent.com/EZhfN-lJEj9khQSIiJ6ZIKXGu2aLaZT2CRNOwVCfuiXfNAv3ae0JGAVw8DbtdKpbQ-9T3orGrd9QuQ=w2880-h1632">
</p>

<p align="center">
  <img width="511" height="1666" src="https://lh3.googleusercontent.com/MltSQAtD3KDU1idNFdXtsql0PIMr6wmzFVZRnaHDsonAXZ1ZHHi5XX8GEWdUzQLUArTBWRIhFGjchw=w2880-h1632">
</p>

**Save and load**

A simple demonstration of saving and loading your models from a binary file.

<p align="center">
  <img width="732" height="633" src="https://lh4.googleusercontent.com/i75sj60N-wCx5fPi4YMWOxWsZybURF_Irhcxa__w2ZMTnRH7c-T9lh-g6ycrbU5zvjkfMCVwSfGhlQ=w2880-h1632">
</p>

## Authors

* **Denis Silko** - *Initial work* - [silkodenis](https://github.com/silkodenis)

## License

[Apache License 2.0](LICENSE)
