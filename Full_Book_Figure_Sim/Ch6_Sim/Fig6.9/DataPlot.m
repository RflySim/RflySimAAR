figure;
hold on;
n = 351;
simCom1=simCom;
simCom1(:,3)=-simCom1(:,3);
t=0:0.04:14;
l1 = plot(t, simCom1(1:n, :), 'Color', [0 0 0], 'LineStyle', '-', 'LineWidth', 1);
l2 = plot(t, simVRMes(1:n, :), 'Color', [0 0 0], 'LineStyle', '--', 'LineWidth', 1);

xlabel('$t,(s)$', 'Interpreter', 'latex');
ylabel('$\Delta x, \Delta y, \Delta z, (m)$', 'Interpreter', 'latex');

legend([l1(1), l2(1)], {'Vision Measurement', 'Real Value'}, 'Interpreter', 'latex', 'Location', 'best');

annotation('textarrow',[.53 .475],[.5 .5],'String','$\Delta x$', 'Interpreter', 'latex');
annotation('textarrow',[.265 .19],[.9 .88],'String','$\Delta y$', 'Interpreter', 'latex');
annotation('textarrow',[.5 .45],[.72 .77],'String','$\Delta z$', 'Interpreter', 'latex');

box on;
hold off;

