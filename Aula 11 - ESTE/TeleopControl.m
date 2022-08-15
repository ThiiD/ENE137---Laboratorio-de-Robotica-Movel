clc, clear all, close all;
% fclose(instrfind);
% ---------------------- Configurações de velocidade ----------------------
% ---------- Velocidade reto ----------
vel_left_reto  = 0.2;
vel_right_reto = 0.2;

% ---------- Velocidade esquerda ----------
vel_left_turn_left  = 0.1;
vel_right_turn_left = 0.2;

% ---------- Velocidade direita ----------
vel_left_turn_right  = 0.2;
vel_right_turn_right = 0.1;

% ---------- Velocidade ré ----------
vel_left_re  = -0.2;
vel_right_re = -0.2;

% --------------------- Configurações de Comunicação ----------------------
portaSerial = 'COM14';

if(~exist('arduino', 'var'))
    arduino = configSerial(portaSerial);
    pause(2);
    try
        disp('Digite a opcao desejada: ');
        ch = getkey();
        while(ch ~=  27)
            if ch == 30                                                     % up arrow
%                 sendVelocity(vel_left_reto, vel_right_reto)
                vD = single(vel_left_reto);
                vE = single(vel_right_reto);
            elseif ch == 31                                                 % down arrow
%                 sendVelocity(vel_left_re, vel_right_re)
                vD = single(vel_left_re);
                vE = single(vel_right_re);  
            elseif ch == 29                                                 % right arrow
%                 sendVelocity(vel_left_turn_right, vel_right_turn_right)
                vD = single(vel_left_turn_right);
                vE = single(vel_right_turn_right);
            elseif ch == 28                                                 % right left
%                 sendVelocity(vel_left_turn_left, vel_right_turn_left)
                vD = single(vel_left_turn_left);
                vE = single(vel_right_turn_left);
            end
%             sendVelocity(vel_left_reto, vel_right_reto)   
% -------------------------------------------------------------------------
%             vD = single(vel_left_turn_right);
%             vE = single(vel_right_turn_right);

            vDarray = typecast(vD,'uint8');
            vEarray = typecast(vE,'uint8');

            msg = [ 1 vDarray vEarray ];

            for i=1:length(msg)
                fwrite(arduino, msg(i));
            end
% -------------------------------------------------------------------------
            ch = getkey();
        end
        fclose(arduino);
    catch
        fclose(arduino);
    end
end
