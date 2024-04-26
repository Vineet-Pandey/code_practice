#include <iostream>
#include <vector>
#include <algorithm>

class Meeting
{
private:
    // number of 30 min blocks past 9:00 am
    unsigned int startTime_;
    unsigned int endTime_;

public:
    Meeting() :
        startTime_(0),
        endTime_(0)
    {
    }

    Meeting(unsigned int startTime, unsigned int endTime) :
        startTime_(startTime),
        endTime_(endTime)
    {
    }

    unsigned int getStartTime() const
    {
        return startTime_;
    }

    void setStartTime(unsigned int startTime)
    {
        startTime_ = startTime;
    }

    unsigned int getEndTime() const
    {
        return endTime_;
    }

    void setEndTime(unsigned int endTime)
    {
        endTime_ = endTime;
    }

    bool operator==(const Meeting& other) const
    {
        return
            startTime_ == other.startTime_
            && endTime_ == other.endTime_;
    }

};
auto mergeRanges(std::vector<Meeting> meet_vector) ->std::vector<Meeting> {
    std::vector<Meeting> sorted_meet_vector;
    auto sort  = [](std::vector<Meeting>&unsorted_vector)  {
        int vector_size = unsorted_vector.size();
        for (int j=0; j<vector_size-1; j++) {
            for (int i=0; i<vector_size-j-1; i++ ) {
                if (unsorted_vector[i].getStartTime()>unsorted_vector[i+1].getStartTime()) {
                    std::swap(unsorted_vector[i],unsorted_vector[i+1]);
                }
            }
        }

        return unsorted_vector;
    };

    sorted_meet_vector = sort(meet_vector);

    auto merge = [&](std::vector<Meeting> &sorted_vector) {
        std::vector<Meeting> merged_meetings;
        merged_meetings.reserve(sorted_vector.size());
        merged_meetings.push_back(sorted_meet_vector.front());
        for(Meeting current_meeting: sorted_meet_vector) {
            Meeting last_meeting = merged_meetings.back();

            if(current_meeting.getStartTime()<=last_meeting.getEndTime()) {
                last_meeting.setEndTime(std::max(current_meeting.getEndTime(),last_meeting.getEndTime()));
            }
            else {
                merged_meetings.push_back(current_meeting);
            }
        }

        return merged_meetings;

    };



return merge(sorted_meet_vector);

}


int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector <Meeting> meet_vector ={Meeting(0, 1),Meeting(4, 8), Meeting(3, 5),
         Meeting(10, 12), Meeting(9, 10)
};
  auto merged_meetings =  mergeRanges(meet_vector);
    for (auto v:merged_meetings) {
        std::cout<<"start times of the merged meetings are: "<<v.getStartTime() <<"and the end time is: "<<v.getEndTime()<< std::endl;
    }
    return 0;
}
