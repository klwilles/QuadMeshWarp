QuadMeshWarp
============

This OpenFrameworks addon allows you to warp panels with the FBO

We used 4 projectors to display a 23'x8' image. Each panel could be manipulated by warping code to correct curve distortion. 

When a panel is activated, you can modify the points along the mesh for warping. Mesh warp coordinates are saved into 4 separate XML files. Look at the imageSplitter.cpp file for keyboard commands. 

Ben Norskov wrote the majority of the code and the FBO addon was used from this site. You will need to find the appropriate addon dependencies and build (which can be tricky, view README files for more info). I tested this out yesterday on the PC and it worked great. When we used it for the event, it worked without a problem. 

I wish we could make this source code more user friendly but I think you all can make it work if you need to. This is the last of the open source files from the Interactive Wall of Spirituality project. 

Moving forward, it would be nice to 

1. integrate edge-blending, 
2. make it easy to define number of projectors and meshes,
3. luminance control per projector. 
4. and make it easier to setup.