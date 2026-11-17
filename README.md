# SMG2 OceanRestored

## Bringing OceanBowl and OceanRing to SMG2

This is the long awaited port of OceanBowl and OceanRing to SMG2!

Below is a list of everything that's included:
- The OceanBowl object for placing down in a level editor.
- The OceanRing object for placing down in a level editor.

Below is a list of other things that you will need:
- A level editor.
- A UseResource with the following sound labels for OceanRing: `SE_AT_LV_OCEAN_RING` and `SE_AT_LV_OCEAN_RING_SUB`.

## Credits
- @shibboleet - Decompilation.
- @superhackio - Decompilation. Ported and enhanced SMG1 code to SMG2.

## Setup
It is adviced to reference the [template mod](https://youtu.be/GSz7fjOaZf0) for this port. You can use the following parameters:

### OceanBowl
| Parameter | Description |
| --- | --- |
| scale_x | X size. The radius of the bowl, multiplied by 100. For example: if set to 5, the bowl will have an effective diameter of 1000 units. |
| Obj_arg7 | MR::registerDemoSimpleCastAll |

### OceanRing
| Parameter | Description |
| --- | --- |
| Obj_arg0 | Draw halfpipe? If set, the visible halfpipe model is rendered. Mario will be able to swim inside the halfpipe regardless of being drawn or not. |
| Obj_arg1 | Segment count. The number of segments that OceanRing uses. Default 30. |
| Obj_arg2 | Lower wave height. Default 80. Some presets to use: 20 for low waves, 50 for medium waves and 80 for high waves. |
| Obj_arg3 | Upper wave height. Default 100. Some presets to use: 30 for low waves, 80 for medium waves and 100 for high waves. |
| Obj_arg7 | Low distance. The distance from Mario at which a segment will use the low model to save performance. Default 13000. |
| point_Arg0 | Flow rate. The speed at this Path Point at which Mario is being pushed around when swimming inside. Does not work on the surface. If set, Mario also cannot swim against the flow of the water anymore. |
| point_Arg1 | Ring width. The width of the ring and halfpipe at this Path Point. The math behind this takes the current and next path point into consideration, however is too complex to explain. It's best to trial and error. Try a value like 10 first. |

### OceanRingAndFlag
Not yet implemented.

### OceanSphere
This module also allows you to change the visuals of OceanSphere, which originally were hardcoded to specific levels in SMG1.
| Parameter | Description |
| --- | --- |
| Obj_arg0 | Style.<br>0 = Default (Water gets transparent when the camera enters it and becomes opaque when the camera leaves).<br>1 = Bonefin Galaxy (Water gets transparent when the camera enters it and stays transparent, even when the camera leaves).<br>2 = Drip Drop Galaxy (Same as 0, but uses a brighter blue color). |
