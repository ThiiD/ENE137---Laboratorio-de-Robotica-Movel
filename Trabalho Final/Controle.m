clc, clear all, close all;
% fclose(instrfind);
portaSerial = ('COM13');
if(~exist('arduino','var'))
    arduino = configSerial(portaSerial);
    %-------------------------------------------
    %--------- Controle de Posição -------------
    %-------------------------------------------
    obj = 1;
    pos = 0;
    velRef = 0.2 + (obj - pos)*0.3;
    while pos ~= obj
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
    vel(contador,1) = fscanf(arduino, '%f');
    vel(contador,2) = fscanf(arduino, '%f');               
    
    dt = toc
    pos = pos + 
            
            
            pause(0.01);
    end
    
    velRef = 0.2 + (obj - pos)*0.3;
        
    
    %-------------------------------------------
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
    
    tic;
    while tempo < 10
        dt = toc;
            if(dt > 0.2)
                tempo = tempo + dt;
                tic;
                contador = contador + 1; % será utilizado na próxima prática
                for i=1:length(msg)
                    fwrite(arduino, msg(i));
                end
                vel(contador,1) = fscanf(arduino, '%f')
                vel(contador,2) = fscanf(arduino, '%f')                
            end
            pause(0.01);
    end
    
    msg = [1 typecast(0,'uint8') typecast(0,'uint8')];


        for i=1:length(msg)
            fwrite(arduino, msg(i));
        end

fclose(arduino);
end

subplot(2,1,1)
plot(vel(:,1))
subplot(2,1,2)
plot(vel(:,2))