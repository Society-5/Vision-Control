# Vision-Control

Real-time QR code and barcode detection from a phone's camera stream, written in C++ with OpenCV and ZBar. This is the first vision prototype for the Society-5 Robosapien robot.

## What it does

1. Opens an MJPEG stream from an Android IP-camera app (`http://<phone-ip>:8080/video`).
2. Converts each frame to grayscale and wraps it as a ZBar `Y800` image.
3. Runs ZBar's `ImageScanner` with every symbology enabled.
4. Prints the type and decoded text of every code it finds.
5. Draws each code's outline on the frame. If ZBar returns more than four corners, it draws their convex hull.

## Files

| File | Purpose |
|---|---|
| `main.cpp` | Capture loop: read frame → decode → display |
| `decode.hpp` | ZBar wrapper; calls a callback for each decoded symbol |
| `decode_object.hpp` | `decodedObject` struct (type, data, corner points) |
| `cover_to_display.hpp` | Draws the code outlines and shows the frame |
| `zbar-test.jpg` | Sample image for testing the decoder |

## Build and run

Requires OpenCV and libzbar (`sudo apt install libopencv-dev libzbar-dev`).

```bash
make
./main
```

The camera URL is hardcoded in `main.cpp`. Change it to match your phone's IP address.

The follow-up project, [Mapping](https://github.com/Society-5/Mapping), uses this pipeline to steer the robot.

---

Part of **[Society-5](https://github.com/Society-5)**: a WowWee Robosapien X that explores a floor on its own, using a phone camera and QR codes as markers, with a mixed-reality (VR) interface for remote control. See [Introduction](https://github.com/Society-5/Introduction) for the project overview.
