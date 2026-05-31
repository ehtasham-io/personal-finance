#include "SavingsGoal.h"
#include <iostream>

SavingsGoal::SavingsGoal(const std::string& name, double target, const std::string& dl)
    : goalName(name), targetAmount(target), currentAmount(0), deadline(dl) {
    milestonesPercentages = {0.25, 0.5, 0.75, 1.0};
    milestonesRewards = {"Bronze Milestone!", "Silver Milestone!", "Gold Milestone!", "Goal Achieved!"};
}

void SavingsGoal::displayProgress() const {
    std::cout << "Goal: " << goalName << " | Progress: " << currentAmount << "/" << targetAmount << std::endl;
}

void SavingsGoal::addToGoal(double amt) {
    currentAmount += amt;
    if (currentAmount > targetAmount) currentAmount = targetAmount;
}

std::string SavingsGoal::checkMilestones() const {
    double percent = currentAmount / targetAmount;
    for (int i = 3; i >= 0; --i) {
        if (percent >= milestonesPercentages[i]) {
            return milestonesRewards[i];
        }
    }
    return "";
}

bool SavingsGoal::isGoalAchieved() const {
    return currentAmount >= targetAmount;
}

double SavingsGoal::getCurrentAmount() const { return currentAmount; }
double SavingsGoal::getTargetAmount() const { return targetAmount; }
std::string SavingsGoal::getGoalName() const { return goalName; }