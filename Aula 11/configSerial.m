function obj = configSerial(portaSerial)
obj = serial(portaSerial);
set(obj, 'DataBits', 8);
set(obj, 'StopBits', 1);
set(obj, 'BaudRate', 9600);
set(obj, 'Parity', 'none');

fopen(obj);

dado = 'b';

    while(dado ~= 'a')
        dado = fscanf(obj, '%s');
    end
    disp('Serial comunicando!');
    fprintf(obj, '%c', 'a');
end