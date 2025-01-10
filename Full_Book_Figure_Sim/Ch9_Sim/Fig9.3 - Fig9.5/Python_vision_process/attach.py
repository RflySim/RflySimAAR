import PX4MavCtrlV4 as PX4MavCtrl

mav = PX4MavCtrl.PX4MavCtrler(20100)
mav.initUE4MsgRec()

drogue_ball_scale = 0.02
drogue_balls = 7
drogue_ball_ids = []
drogue_ball_poses = [[1.25, 0, 0.62], [1.25, 0.4, 0.47], [1.25, 0.61, -0.13], [1.265, 0.25, -0.58], [1.265, -0.47, -0.4], [1.265, -0.62, 0], [1.265, -0.47, 0.4]]
for i in range(drogue_balls):
    drogue_ball_ids.append(100 + i)
    mav.sendUE4PosScale(100 + i, 152, PosE=drogue_ball_poses[i], Scale=[drogue_ball_scale] * 3)

drogue_copter_id = 31
mav.sendUE4Attatch(drogue_ball_ids, [drogue_copter_id] * drogue_balls, [3] * drogue_balls)

drogue_ball_scale = 0.2
tanker_balls = 6
tanker_ball_ids = []
tanker_ball_poses = [[-2, 0, 0], [-2, -18, -4.8], [-4, -8, -3], [-2, 18, -4.8], [-4, 8, -3], [-17, 0, -4]]
for i in range(tanker_balls):
    tanker_ball_ids.append(107 + i)
    mav.sendUE4PosScale(107 + i, 1152, PosE=tanker_ball_poses[i], Scale=[drogue_ball_scale] * 3)

tanker_copter_id = 10
mav.sendUE4Attatch(tanker_ball_ids, [tanker_copter_id] * tanker_balls, [3] * tanker_balls)

mav.endUE4MsgRec()
