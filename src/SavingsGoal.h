#ifndef SAVINGS_GOAL_H
#define SAVINGS_GOAL_H
#include <string>
#include <array>

class SavingsGoal {
    std::string goalName;
    double targetAmount;
    double currentAmount;
    std::string deadline;
    std::array<double, 4> milestonesPercentages;
    std::array<std::string, 4> milestonesRewards;
public:
    SavingsGoal(const std::string& name, double target, const std::string& deadline);
    void displayProgress() const;
    void addToGoal(double amt);
    std::string checkMilestones() const;
    bool isGoalAchieved() const;
    double getCurrentAmount() const;
    double getTargetAmount() const;
    std::string getGoalName() const;
};

#endif