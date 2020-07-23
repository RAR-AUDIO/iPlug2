# **RARClasses**

Supported OS:   
macOS 10.7+  
Windows 7+

Supported IDE:  
Visual Studio 2017  
Xcode 7+

***

## Included classes
Besides others: RAR_Constants which holds specific variables and classes used in all (future) RAR_ plugins.

***

## DSP
DSP classes mostly without dependencies.
### RAR_Buffer
Simple multichannel buffer, depends on WDL (Ptrlist and Typedbuf)
### RAR_Gain
Gain and pan classes with gain smoother.
### RAR_Filters
Mainly biquad filters and some others, based on Earlevel biquad classes and some other resources.
### RAR_Dynamics
Dynamics classes including compressors, limiters, gate, deesser and so on. More or less based on chunkware simple classes.
### RAR_Saturation
Some waveshapers.

***

## Utils
### RAR_Helpers
Some helpers for unit conversion and so on. Without dependencies.
### RAR_Graphics
Specific IPlug2 controls inherited from IControl.
### RAR_Param
Parameter Smoothing.
### RAR_Constants
Constant variables for Classes.

***

## Versioning

For transparency and insight into our release cycle, and for striving to maintain backward compatibility, _**RARClasses**_ will be maintained according to the [Semantic Versioning](http://semver.org/) guidelines as much as possible.

Releases will be numbered with the following format:

`<major>.<minor>.<patch>-<build>`

Constructed with the following guidelines:

* A new *major* release indicates a large change where backward compatibility is broken.
* A new *minor* release indicates a normal change that maintains backward compatibility.
* A new *patch* release indicates a bugfix or small change which does not affect compatibility.
* A new *build* release indicates this is a pre-release of the version.

***

Copyright © 2020 and later RAR-AUDIO LLC.
