clc, clear all, close all;
%fclose(instrfind);
portaSerial = ('COM13');
if(~exist('arduino','var'))
    arduino = configSerial(portaSerial);
    vD = 0.2;
    vE = 0.2;
    tempo = 0;
    contador = 0;
    
    vD = single(vD);
    vE = single(vE);
    
    vDarray = typecast(vD,'uint8');
    vEarray = typecast(vE,'uint8');
    
    msg = [ 1 vDarray vEarray ];
    
    pause(2);
    
    tic;
    while tempo < 10
        dt = toc;
            if(dt > 0.2)
            tempo = tempo + dt;
            tic;
             for i=1:length(msg)
                fwrite(arduino, msg(i));
             end             
               contador = contador + 1; % será utilizado na próxima prática
            end
            pause(0.01);
    end
fclose(arduino);
end