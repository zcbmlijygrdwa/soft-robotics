close all;
clear all;

addpath('/home/zhenyu/matlabplugins')

t = 0:0.01:20;
pitch_data = zeros(1,length(t));
roll_data = zeros(1,length(t));

pump1_input = 0;
pump2_input = 0;
pump3_input = 0;
pump4_input = 0;

openVolt = 7;

pump1_data = zeros(1,length(t));
pump2_data = zeros(1,length(t));
pump3_data = zeros(1,length(t));
pump4_data = zeros(1,length(t));

pid1_data = zeros(1,length(t));
pid2_data = zeros(1,length(t));


pitch = 0;
roll = 0;

pid1_output = 0;
pid2_output = 0;


for i = 1:length(t)
    
    roll =  roll+(rand()-0.5)/1000;
    pitch =  pitch+(rand()-0.5)/1000;
    
    if(i>=150&&i<=220)
        roll = roll+(rand()/30);
    end
    
    if(i>=450&&i<=620)
        pitch = pitch+(-rand()/30);
    end
    
    if(i==1200)
        roll = -0.7+(rand()-0.8)/10;
    end
    
    if(i>1200&&i<=1260)
        roll = roll+(-rand())/30;
    end
    
    if(i>=500&&i<=670)
        roll =  roll+(rand()-0.5)/300;
    end
    
    if(i>=850&&i<=1050)
        pitch =  i/10000 + (rand()-0.5)/30;
    end
    
    pump1_input = myController(-roll,openVolt);
    pump3_input = myController(roll,openVolt);
    
    pump2_input = myController(-pitch,openVolt);
    pump4_input = myController(pitch,openVolt);
    
    angles = pumpPlant(pump1_input,pump2_input,pump3_input,pump4_input,[roll,pitch]);
    roll = angles(1);
    pitch = angles(2);
    
    
    pitch_data(i) = pitch;
    roll_data(i) = roll;
    
    pump1_data(i) = pump1_input;
    pump3_data(i) = pump3_input;
    
    pump2_data(i) = pump2_input;
    pump4_data(i) = pump4_input;
    
end

pumps_data{1} = pump1_data;
pumps_data{2} = pump2_data;
pumps_data{3} = pump3_data;
pumps_data{4} = pump4_data;

rotation_data{1} = pitch_data;
rotation_data{2} = roll_data;
plotF(openVolt,rotation_data,pumps_data,0,length(t))
plotF(openVolt,rotation_data,pumps_data,120,250)
plotF(openVolt,rotation_data,pumps_data,450,700)
plotF(openVolt,rotation_data,pumps_data,700,1100)
plotF(openVolt,rotation_data,pumps_data,1100,1350)
