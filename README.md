# ReticleWindowsTest
A little test setup for Reticle on windows.

### Steps to use:

 -  Clone/Fork.
 -  Change all link library paths in Test1.cbp to correctly point at Reticle root.
 -  Also make sure linking to OpenGL and libgdi32.a are correct for your platform.
 -  Change compiler and linker search directories to correctly point at Reticle root.
 -  Change the line in main.cpp with a call to `RetiRenderer::setReticleRootDirectory()`  to `RetiRenderer::setReticleRootDirectory("[Platform Specifically Formatted Absolute Path to Reticle root]");`.
 -  Change the line creating a `RetiSceneObject` so that the string passed to the constructor is a platform specificall formatted path (preferably absolute) to the 3D asset file you wish to see in Reticle.
 -  Build and Run.

### Some instructions for manipulating transforms:

	You may have noticed code like `obj.getTransform().rotateTransform(...)` etc. They do exactly what you would think.

