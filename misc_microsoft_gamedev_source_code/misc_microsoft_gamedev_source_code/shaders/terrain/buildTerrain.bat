p4 edit ..\..\work\shaders\terrain\gpuTerrainXbox.bin
cd terrain
rem "C:\Program Files\Microsoft Xbox 360 SDK\bin\win32\fxc.exe" "gpuTerrainXbox.fx" /Gfp /Xsampreg:0-15,16-24 /T fxl_3_0 /Fo ..\..\..\work\shaders\terrain\gpuTerrainXbox.bin
rem "C:\Program Files\Microsoft Xbox 360 SDK\bin\win32\fxc.exe" "gpuTerrainXbox.fx" /Gfp /Xsampreg:0-15,16-24 /T fxl_3_0 /Fc gpuTerrainXbox.asm 

"C:\Program Files\Microsoft Xbox 360 SDK\bin\win32\fxc.exe" "gpuTerrainXbox.fx" /Xsampreg:0-15,16-25 /T fxl_3_0 /Fo ..\..\..\work\shaders\terrain\gpuTerrainXbox.bin
"C:\Program Files\Microsoft Xbox 360 SDK\bin\win32\fxc.exe" "gpuTerrainXbox.fx" /Xsampreg:0-15,16-25 /T fxl_3_0 /Fc gpuTerrainXbox.asm 

cd ..
