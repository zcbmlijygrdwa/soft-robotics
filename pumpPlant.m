function angles = pumpPlant(p1,p2,p3,p4,angles)

%  | 1     2 |
%  |         |
%  |         |
%  | 4     3 |
roll = angles(1);
pitch = angles(2);

pitch = pitch+atan(p2 - p4 + (rand()-0.5))*0.01;
roll = roll +atan( p1 - p3 + (rand()-0.5))*0.01;

angles = [roll,pitch];


end