function plotF(openVolt,rotation_data,pumps_data,startTime,endTime)
pump1_data = pumps_data{1};
pump2_data = pumps_data{2};
pump3_data = pumps_data{3};
pump4_data = pumps_data{4};


pitch_data = rotation_data{1};
roll_data = rotation_data{2};


figure()
subplot(5,1,1)
plot(pitch_data)
hold on
plot(roll_data)
hold off
title('roll and pitch')
legend('pitch','roll')
xlim([startTime,endTime])
xlabel('time(ms)')
ylabel('angle(radian)')

subplot(5,1,2)
plot(pump1_data)
xlim([startTime,endTime])
ylim([-0.5,openVolt+0.5])
title('pump1 inputs')
%legend('pump1-input','pump2-input','pump3-input','pump4-input')
xlabel('time(ms)')
ylabel('voltage(volt)')

subplot(5,1,3)
plot(pump2_data)
xlim([startTime,endTime])
ylim([-0.5,openVolt+0.5])
title('pump2 inputs')
%legend('pump1-input','pump2-input','pump3-input','pump4-input')
xlabel('time(ms)')
ylabel('voltage(volt)')

subplot(5,1,4)
plot(pump3_data)
xlim([startTime,endTime])
ylim([-0.5,openVolt+0.5])
title('pump3 inputs')
%legend('pump1-input','pump2-input','pump3-input','pump4-input')
xlabel('time(ms)')
ylabel('voltage(volt)')

subplot(5,1,5)
plot(pump4_data)
xlim([startTime,endTime])
ylim([-0.5,openVolt+0.5])
title('pump4 inputs')
%legend('pump1-input','pump2-input','pump3-input','pump4-input')
xlabel('time(ms)')
ylabel('voltage(volt)')


end