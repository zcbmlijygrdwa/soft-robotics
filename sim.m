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

figure(1)
subplot(5,1,1)
plot(pitch_data)
hold on
plot(roll_data)
hold off
title('roll and pitch')
legend('pitch','roll')
xlabel('time(ms)')
ylabel('angle(radian)')
% 
% subplot(5,1,2)
% plot(pump1_data)
% hold on
% plot(pump2_data)
% plot(pump3_data)
% plot(pump4_data)
% hold off
% %ylim([-0.5,6.5])
% title('pump inputs')
% %legend('pump1-input','pump2-input','pump3-input','pump4-input')
% xlabel('time(ms)')
% ylabel('voltage(volt)')


subplot(5,1,2)
plot(pump1_data)
ylim([-0.5,openVolt+0.5])
title('pump1 inputs')
%legend('pump1-input','pump2-input','pump3-input','pump4-input')
xlabel('time(ms)')
ylabel('voltage(volt)')

subplot(5,1,3)
plot(pump2_data)
ylim([-0.5,openVolt+0.5])
title('pump2 inputs')
%legend('pump1-input','pump2-input','pump3-input','pump4-input')
xlabel('time(ms)')
ylabel('voltage(volt)')

subplot(5,1,4)
plot(pump3_data)
ylim([-0.5,openVolt+0.5])
title('pump3 inputs')
%legend('pump1-input','pump2-input','pump3-input','pump4-input')
xlabel('time(ms)')
ylabel('voltage(volt)')

subplot(5,1,5)
plot(pump4_data)
ylim([-0.5,openVolt+0.5])
title('pump4 inputs')
%legend('pump1-input','pump2-input','pump3-input','pump4-input')
xlabel('time(ms)')
ylabel('voltage(volt)')