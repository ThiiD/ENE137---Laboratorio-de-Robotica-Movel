clc, clear all, close all

data = load('t100a11');
pv = 48;
D = 0.042;
dT = 0.1;
dS = ((pi*D)/pv)/dT;

y = dS*data.d(:,2);
u = data.d(:,1);
N = length(y);

Y = y(2:N);
X = [y(1:N-1) u(1:N-1)];

theta = inv(X'*X)*X'*Y

yh = [0];
for i = 2:N
    yh(i) = theta(1) *  y(i - 1) + theta(2) * u(i-1);    
end


% ----------- Validação ---------
data_t = load('t100a12');
y_t = dS*data_t.d(:,2);
u_t = data_t.d(:,1);

yh_t = [0];
for i = 2:N
    yh_t(i) = theta(1) *  y_t(i - 1) + theta(2) * u_t(i-1);    
end


% ------------ Plots -----------
figure()
subplot(2,2,1)
plot(data.dT, y, 'b', 'linewidth', 2)
hold on
plot(data.dT, yh, 'r','linewidth', 2)
hold on
grid on
title('Identificação do Sistema')
xlabel('Tempo [s]')
ylabel('Velocidade [m/s]')
legend('Medido','Calculado') 

subplot(2,2,3)
plot(data.dT, u, 'k', 'linewidth', 2)
grid on
legend('Entrada')
xlabel('Tempo [s]')
ylabel('Duty Cycle')
hold off


subplot(2,2,2)
plot(data_t.dT, y_t, 'b', 'linewidth', 2)
hold on
plot(data_t.dT, yh_t, 'r','linewidth', 2)
hold on
grid on
title('Validação do Sistema')
xlabel('Tempo [s]')
ylabel('Velocidade [m/s]')
legend('Medido','Calculado') 

subplot(2,2,4)
plot(data_t.dT, u_t, 'k', 'linewidth', 2)
grid on
legend('Entrada')
xlabel('Tempo [s]')
ylabel('Duty Cycle')
suptitle('Roda esquerda sem carga (anti-horario)')
hold off