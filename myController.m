function output = myController(input,openVolt)
% 0.5 degree = (0.5/180)*3.14 rad = 0.0087 rad

    if(input>0.03)
        %output = 6;
        output = openVolt + rand/10;%noise
        
    else
        output = 0;
    end

end