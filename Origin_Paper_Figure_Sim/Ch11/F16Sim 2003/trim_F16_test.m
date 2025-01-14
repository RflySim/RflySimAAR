function [trim_control,alpha] = trim_F16_test()
% ��������������ʼ���������ڲ�ͬ�߶Ⱥ��ٶ��£����в�ͬģʽ�£��ߵͿգ���
% ...״̬�����Ϳ������ĳ�ʼλ��
%
% trim_state = xu(1:12) �Ƿɻ���12ά״̬�ռ�ĳ�ֵ���ֱ���
%           ��npos      ��epos      ��altitude
%           ��ת��roll  ������pitch  ƫ����yaw
%           ���ٶ�Vt    ӭ��alpha    �໬��beta
%           ��ת���ٶ�p �������ٶ�q   ƫ�����ٶ�r
%
% trim_thrust ���� ���� ��ʼλ��
%
% trim_control ���� �����桢��������� �ĳ�ʼλ��
%
% dLEF�ǽ���ĳ�ʼλ�ã��߿�ģʽ��0~25��֮�䣬�Ϳ�ģʽ����0��


%================================================
%     F16 nonlinear model trimming routine
%  for longitudinal motion, steady level flight
%
% Author: T. Keviczky
% Date:   April 29, 2002
%
%
%      Added addtional functionality.
%      This trim function can now trim at three 
%      additional flight conditions
%         -  Steady Turning Flight given turn rate
%         -  Steady Pull-up flight - given pull-up rate
%         -  Steady Roll - given roll rate
%
% Coauthor: Richard S. Russell
% Date:     November 7th, 2002
%
%
%================================================

fcn='F16trim';
load_system(fcn);

UX0 = [0; 0; 0; 0; 0];  % free parameters: two control values & angle of attack

% Initializing optimization options and running optimization:
OPTIONS = optimset('TolFun',1e-10,'TolX',1e-10,'MaxFunEvals',5e+04,'MaxIter',1e+04);

try
    % Pre-compile the model
    feval(fcn, [], [], [], 'lincompile');
    iter = 1;
    while iter == 1

        % UX0�ǳ�ֵ����trimfun����������UX����Сֵ����Ϊ��ǰ�߶Ⱥ��ٶȵ���ֵ̬
        % ���������ǣ����ţ�����ƫ���Լ�ӭ�ǵĳ�״̬
        [UX,FVAL,EXITFLAG,OUTPUT] = fminsearch('trimfun_F16',UX0,OPTIONS);
        [cost, Xdot, xu] = trimfun_F16(UX);
        disp('Trim Values and Cost:');
        disp(['cost   = ' num2str(cost)]);
        % ��ͨ��trimfun�͵õ���UX���㣬��ʼ����xu����ϵͳ���룬18����
        % ��costӦ�����������Ż��ģ�Ҳ������һ���õ�
        Xdot
        xu
        flag = input('Continue trim rountine iterations? (y/n):  ','s'); 
        if flag == 'n'
            iter = 0;
        end
        UX0 = UX;
    end

catch Ex
    % Clean up 
    feval(fcn, [], [], [], 'term');
    rethrow(Ex)
end
feval(fcn, [], [], [], 'term');

trim_control=UX0(1:4);
alpha=UX0(5);

end
