# GPU Filters

Four image processing filters implemented in pure C and in OpenCL to compare their performances.

**Edge Detection** with Canny's algorithm

Raw                        |  Processed
:-------------------------:|:-------------------------:
![](readme/canny_raw.png)  |  ![](readme/canny.png)

**Line Detection** with Hough's transform

Raw                        |  Processed
:-------------------------:|:-------------------------:
![](readme/hough_raw.png)  |  ![](readme/hough.png)

**Region Filling** via exemplar-based image inpainting

Raw                        |  Processed
:-------------------------:|:-------------------------:
![](readme/inpainting_raw.png)  |  ![](readme/inpainting_raw.png)

**Dense Optical Flow** with Lucas-Kanade

Raw                        |  Processed
:-------------------------:|:-------------------------:
![](readme/kanade_raw.png)  |  ![](readme/kanade_raw.png)

# Dependencies
* ### OpenCL 1.2 with C++ bindings 

<img src="https://www.eriksmistad.no/wp-content/uploads/OpenCL_Logo_RGB1.png" alt="drawing" width="180" align="right"/>

Filters are implemented using OpenCL 1.2. To download needed headers and libraries (linux) for compilation run:


```shell
sudo apt install ocl-icd-libopencl1
sudo apt install opencl-headers
sudo apt install clinfo
```

We've also used the C++ bindings, which are included in the repo.

A device that supports OpenCL is needed to run the program. Drivers installation varies. These are some devices in which the program ran and how to install their drivers:

**NVIDIA GeForce 940m**

```shell
sudo add-apt-repository ppa:graphics-drivers/ppa
sudo apt-get update
sudo apt-get install nvidia-355 nvidia-prime
sudo reboot
```


* ### OpenCV 2

<img src="https://opencv.org/assets/theme/logo.png" alt="drawing" width="80" align="right"/>

For camera input only. **Central algorithms are not implemented using this library.**

To get eveything needed to compile run:

```shell
sudo apt-get install libopencv-dev
```
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/fc/Qt_logo_2013.svg/498px-Qt_logo_2013.svg.png" alt="drawing" width="80" align="right"/>

* ### Qt 4.8
For an advanced GUI only, not actually needed to run the bascis. More information at `gui/readme.md`

# What is left
- [x] Better line drawing algorithm
- [x] Lucas-Kanade C version
- [x] Lucas-Kanade OpenCL version
- [x] Hough line-detection OpenCL version
- [x] Inpainting OpenCL version
- [ ] Handle boundaries (image borders) in all algorithms
- [ ] Optimize all OpenCL code
- [ ] Test / validate current implementations
- [x] Create a friendly UI
- [ ] Fix Canny C bugs
