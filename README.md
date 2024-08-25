# C-Ray-on
A 3-D Ray Tracer built using C which relies on Lambertian Reflectance Model to illuminate objects.
Currently only sphere is supported, but more shapes to be added soon.
Fast Approximate Anti-Aliasing (FXAA) supported.

## Usage
Built using C11 on Windows but should also run on Linux.
Run `make`.

## Outputs
### Before/After applying FXAA Post-Processing
<p align="left">
  <img src="assets/nonfxaa.jpg" width="300" height="300"/>
  <img src="assets/fxaa.jpg" width="300" height = "300"/>
</p>

### Light on the face, non-overlapping
<img src="assets/forwardfacingnonoverlapping.jpg" width="300" height="300">

### Light on the right side, non-overlapping
<img src="assets/lighttotherightnonoverlapping.jpg" width="300" height="300">

### Light on the left side, non-overlapping
<img src="assets/lighttotheleftnonoverlapping.jpg" width="300" height="300">

### Light on the right side, overlapping
<img src="assets/lighttotherightoverlapping.jpg" width="300" height="300">


