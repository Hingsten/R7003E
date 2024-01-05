load 5_5_50cm_10s.mat
group_10_experiment_1_times = afTimes;
group_10_experiment_1_encoder = aafProcessedInformation(2,:);
group_10_experiment_1_angle = aafProcessedInformation(3,:);
group_10_experiment_1_actuation = aafProcessedInformation(1,:);
save("group_10_results.mat","group_10_experiment_1_times","group_10_experiment_1_encoder","group_10_experiment_1_angle","group_10_experiment_1_actuation","-append")

load 5_5_200cm_10s.mat
index = 1581:6000;
group_10_experiment_1_times = afTimes(1:length(index));
group_10_experiment_1_encoder = aafProcessedInformation(2,index);
group_10_experiment_1_angle = aafProcessedInformation(3,index);
group_10_experiment_1_actuation = aafProcessedInformation(1,index);
save("group_10_results.mat","group_10_experiment_1_times","group_10_experiment_1_encoder","group_10_experiment_1_angle","group_10_experiment_1_actuation","-append")
