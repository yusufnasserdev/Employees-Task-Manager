#pragma once
#include "Task.h"

struct ComparePriority {
    bool operator()(Task const& t1, Task const& t2)
    {
        if (t1.getPriority() < t2.getPriority()) {
            return true;
        }
        else if (t1.getPriority() == t2.getPriority()) {
            if (t1.getDeadline() < t2.getDeadline()) {
                return true;
            }
        }
        return false;
    }
};

struct CompareDeadline {
    bool operator()(Task const& t1, Task const& t2)
    {
        if (t1.getDeadline() > t2.getDeadline()) {
            return true;
        }
        else if (t1.getDeadline() == t2.getDeadline()) {
            if (t1.getPriority() > t2.getPriority()) {
                return true;
            }
        }
        return false;
    }
};