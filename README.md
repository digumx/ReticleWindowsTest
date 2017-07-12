# ReticleWindowsTest
A little test setup for Reticle on windows.

### License:

ReticleWindowsTest is licensed under the MIT License. See [LICENSE](https://github.com/digumx/ReticleWindowsTest/blob/master/LICENSE) file for details.

### Steps to use:

 -  Clone/Fork.
 -  Change all link library paths in Test1.cbp to correctly point at Reticle root.
 -  Also make sure linking to OpenGL and libgdi32.a are correct for your platform.
 -  Change compiler and linker search directories to correctly point at Reticle root.
 -  Change the line in main.cpp with a call to `RetiRenderer::setReticleRootDirectory()`  to `RetiRenderer::setReticleRootDirectory("[Platform Specifically Formatted Absolute Path to Reticle root]");`.
 -  Change the line creating a `RetiSceneObject` so that the string passed to the constructor is a platform specificall formatted path (preferably absolute) to the 3D asset file you wish to see in Reticle.
 -  Build and Run.

### Some instructions for manipulating transforms:

Some useful transform related tips:

 -  You may have noticed code like `obj.getTransform().rotateTransform(...)` etc. They do exactly what you would think - change the transform of obj. Translate and Scale take three floats, the x, y and z values of the vector by which to translae or scale. Rotate takes 4 values, the first being the angle in radians and the next three representing a vector along the axis of rotation. Note that the vectors passed above are all in Object local space.
 -  Reticle uses a right-handed vector space for all 3D transformations. 
 -  Note the unit in 3D space in Reticle is 1 meter (and camera, input etc will be configured accordingly). Due to this, you may have to scale imported objects up or down.
 -  Also note that in Reticle, the camera is by default located at global origin, looking down global negative Z, with the up direction corresponding to the gobal positive Y. Due to this, it may be necessary to move and rotate objects to be able to see them.
