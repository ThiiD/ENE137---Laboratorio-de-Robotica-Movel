clc, clear all, close all;

% ---------------------- Configurações de velocidade ----------------------
% ---------- Velocidade reto ----------
vel_left_reto = 0;
vel_right_reto = 0;

% ---------- Velocidade esquerda ----------
vel_left_turn_left = 0;
vel_right_turn_left = 0;

% ---------- Velocidade direita ----------
vel_left_turn_right = 0;
vel_right_turn_right = 0;

% ---------- Velocidade ré ----------
vel_left_re = 0;
vel_right_re = 0;


portaSerial = 'COM13';


if(~exist('arduino', 'var'))
    arduino = configSerial(portaSerial);
    try
        disp('Digite a opção desejada: ');
        ch = getkey();
        while(ch ~=  27)
            if ch == 30                                                     % up arrow
                sendVelocity(vel_left_reto, vel_right_reto)
            elseif ch == 31                                                 % down arrow
                sendVelocity(vel_left_re, vel_right_re)
            elseif ch == 29                                                 % right arrow
                sendVelocity(vel_left_turn_right, vel_right_turn_right)
            elseif ch == 29                                                 % right left
                sendVelocity(vel_left_turn_left, vel_right_turn_left)
            end
            ch = getkey();
        end
        fclose(arduino);
    catch
        fclose(arduino);
    end
end
