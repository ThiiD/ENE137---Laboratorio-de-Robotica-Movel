clc, clear all, close all;
% fclose(instrfind);
portaSerial = ('COM15');
if(~exist('arduino','var'))
    arduino = configSerial(portaSerial);
    %-------------------------------------------
    %--------- Controle de Posição -------------
    %-------------------------------------------
    obj = 1;
    pos = 0;
    velRef =(obj - pos)*0.5;
    while pos < obj
    vD = velRef;
    vE = velRef;
    tempo = 0;
    vel = [];    
    vD = single(vD);
    vE = single(vE);
    
    vDarray = typecast(vD,'uint8');
    vEarray = typecast(vE,'uint8');
    
    msg = [ 1 vDarray vEarray ];
            
    for i=1:length(msg)
        fwrite(arduino, msg(i));
    end
    tic
    vel(1) = fscanf(arduino, '%f')
    vel(2) = fscanf(arduino, '%f')
    dt = fscanf(arduino, '%f')
    
    pos = pos + dt*( vel(1) + vel(2))/2000
            
    velRef = (obj - pos)*0.5;
    
    end
    
    velRef = 0
       
    vD = velRef;
    vE = velRef;
    tempo = 0;
    contador = 0;
    vel = [];
    pause(2);
    
    vD = single(vD);
    vE = single(vE);
    
    vDarray = typecast(vD,'uint8');
    vEarray = typecast(vE,'uint8');
    
    msg = [ 1 vDarray vEarray ];
   

        for i=1:length(msg)
            fwrite(arduino, msg(i));
        end

fclose(arduino);
end