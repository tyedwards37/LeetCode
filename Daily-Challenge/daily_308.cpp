/* Daily Question: 731. My Calendar II
 * by Tyler Edwards | September 26th, 2024 
 * Code Credit: otoc
 * You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.
 * A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).
 * The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.
 * Implement the MyCalendarTwo class:
 * - MyCalendarTwo() Initializes the calendar object.
 * - boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. 
 * - Otherwise, return false and do not add the event to the calendar. */

class MyCalendarTwo 
{
    map<int, int> mp; // key: time; val: +1 if start, -1 if end
public:
    bool book(int start, int end) 
    {
        mp[start]++;
        mp[end]--;
        int booked = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) 
        {
            booked += it->second;
            if (booked == 3) 
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};