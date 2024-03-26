﻿#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>

template <typename T>
class Sort {
public:
    static size_t shellSort(T* array[], size_t n) {
        size_t comparisons = 0;
        for (int gap = static_cast<int>(n / 2); gap > 0; gap /= 2) {
            for (size_t i = gap; i < n; ++i) {
                T* temp = array[i];
                size_t j;
                for (j = i; j >= gap && *array[j - gap] > *temp; j -= gap) {
                    ++comparisons;
                    array[j] = array[j - gap];
                }
                array[j] = temp;
            }
        }
        return comparisons;
    }

    static size_t heapSort(T* array[], size_t n) {
        size_t comparisons = 0;
        for (int i = static_cast<int>(n / 2) - 1; i >= 0; i--) {
            heapify(array, n, i, comparisons);
        }
        for (int i = static_cast<int>(n) - 1; i > 0; i--) {
            std::swap(array[0], array[i]);
            comparisons++;
            heapify(array, i, 0, comparisons);
        }
        return comparisons;
    }

private:
    static void heapify(T* array[], size_t n, int root, size_t& comparisons) {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        if (left < n && *array[left] > *array[largest]) {
            largest = left;
        }
        comparisons++;
        if (right < n && *array[right] > *array[largest]) {
            largest = right;
        }
        comparisons++;
        if (largest != root) {
            std::swap(array[root], array[largest]);
            heapify(array, n, largest, comparisons);
        }
    }
};

class Participant {
public:
    Participant(int id, int solved, int time, int points, int attempts)
        : id(id), solved(solved), time(time), points(points), attempts(attempts) {}

    bool operator<(const Participant& other) const {
        if (points != other.points) return points > other.points;
        if (solved != other.solved) return solved > other.solved;
        if (time != other.time) return time < other.time;
        if (attempts != other.attempts) return attempts < other.attempts;
        return id < other.id;
    }

    bool operator>(const Participant& other) const {
        if (points != other.points) return points < other.points;
        if (solved != other.solved) return solved < other.solved;
        if (time != other.time) return time > other.time;
        if (attempts != other.attempts) return attempts > other.attempts;
        return id > other.id;
    }

    friend std::ostream& operator<<(std::ostream& os, const Participant& participant) {
        os << std::setw(5) << participant.id
            << std::setw(10) << participant.solved
            << std::setw(10) << participant.time
            << std::setw(10) << participant.points
            << std::setw(10) << participant.attempts;
        return os;
    }

private:
    int id;
    int solved;
    int time;
    int points;
    int attempts;
};

std::vector<Participant*> readParticipants(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    std::vector<Participant*> participants;
    int id, solved, time, points, attempts;
    while (file >> id >> solved >> time >> points >> attempts) {
        Participant* participant = new Participant(id, solved, time, points, attempts);
        participants.push_back(participant);
    }

    file.close();
    return participants;
}

void writeResults(const std::vector<Participant*>& participants, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        exit(1);
    }

    file << std::setw(5) << "ID"
        << std::setw(10) << "Solved"
        << std::setw(10) << "Time"
        << std::setw(10) << "Points"
        << std::setw(10) << "Attempts" << std::endl;

    for (const auto& participant : participants) {
        file << *participant << std::endl;
    }

    file.close();
}

int main() {
    std::vector<Participant*> participants = readParticipants("participants.txt");

    Sort<Participant>::heapSort(participants.data(), participants.size());

    writeResults(participants, "results.txt");

    for (auto participant : participants) {
        delete participant;
    }

    return 0;
}
