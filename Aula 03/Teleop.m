clc, clear all, close all;

portaSerial = 'COM13';


if(~exist('arduino', 'var'))
    arduino = configSerial(portaSerial);
    try
        disp('Digite a opção desejada: ');
        ch = getkey();
        while(ch ~=  27)
            fwrite(arduino, ch);
            ch = getkey();
        end
        fclose(arduino);
    catch
        fclose(arduino);
    end
end

