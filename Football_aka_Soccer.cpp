#include <iostream>
#include <string>
#include <algorithm>

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;


struct F_team
{
    string name;
    int total_points_earned = 0;
    int games_played = 0;
    int wins = 0;
    int ties = 0;
    int losses = 0;
    int goal_difference = 0;
    int goals_scored = 0;
    int goals_against = 0;
};


void output_ans(F_team team[], int number_of_teams, string Team_name)
{
    fast
    
    cout << Team_name << '\n';
    
    for(int i = 0; i < number_of_teams; i++)
    {
        cout
            << (i + 1) << ") "
            
            << team[i].name << ' ' << team[i].total_points_earned << "p, "
            << team[i].games_played << "g ("
            << team[i].wins << '-' << team[i].ties << '-' << team[i].losses<< "), "
            << team[i].goal_difference << "gd ("
            << team[i].goals_scored << '-' << team[i].goals_against << ")\n"
        ;
    }
}


bool compare(F_team &a, F_team &b)
{
    if(a.total_points_earned != b.total_points_earned)
    {
        return a.total_points_earned > b.total_points_earned;
    }
    
    if(a.wins != b.wins)
    {
        return a.wins > b.wins;
    }
    
    if(a.goal_difference != b.goal_difference)
    {
        return a.goal_difference > b.goal_difference;
    }
    
    if(a.goals_scored != b.goals_scored)
    {
        return a.goals_scored > b.goals_scored;
    }
    
    if(a.games_played != b.games_played)
    {
        return a.games_played < b.games_played;
    }
    
    string s1 = a.name;
    string s2 = b.name;
    
    for(int i = 0; i < s1.size(); i++) s1[i] = tolower(s1[i]);
    for(int i = 0; i < s2.size(); i++) s2[i] = tolower(s2[i]);
    
    return s1 < s2;
    
}


void search_for_data_and_updata_it(string team_1, string team_2, int goals_1, int goals_2, F_team team[], int number_of_teams)
{
    int found_1 = -1, found_2 = -1;
    
    for(int i = 0; i < number_of_teams; i++)
    {
        if(team_1 == team[i].name) found_1 = i;
        
        if(team_2 == team[i].name) found_2 = i;
    }
    
    team[found_1].games_played++;
    team[found_2].games_played++;
    
    team[found_1].goals_scored += goals_1;
    team[found_2].goals_scored += goals_2;
    
    team[found_1].goals_against += goals_2;
    team[found_2].goals_against += goals_1;
    
    team[found_1].goal_difference = team[found_1].goals_scored - team[found_1].goals_against;
    team[found_2].goal_difference = team[found_2].goals_scored - team[found_2].goals_against;;
    
    if(goals_1 > goals_2)
    {
        team[found_1].total_points_earned += 3;
        team[found_1].wins++;
        
        team[found_2].losses++;
    }
    
    else if(goals_1 < goals_2)
    {
        team[found_2].total_points_earned += 3;
        team[found_2].wins++;
        
        team[found_1].losses++;
    }
    
    else
    {
        team[found_1].total_points_earned++;
        team[found_2].total_points_earned++;
        
        team[found_1].ties++;
        team[found_2].ties++;
    }
}


void search_for_team(string match_played, F_team team[], int number_of_teams)
{
    string team_1, team_2;
    
    int hash_1 = match_played.find('#');
    int atsign = match_played.find('@');
    int hash_2 = match_played.find('#', atsign);
    
    team_1 = match_played.substr(0, hash_1);
    
    int goals_1 = stoi(match_played.substr(hash_1 + 1, atsign - hash_1 - 1));
    int goals_2 = stoi(match_played.substr(atsign + 1, hash_2 - atsign - 1));
    
    team_2 = match_played.substr(hash_2 + 1);
    
    search_for_data_and_updata_it(team_1, team_2, goals_1, goals_2, team, number_of_teams);
}


void processesing(F_team team[], int number_of_teams)
{
    int number_of_games;
    cin >> number_of_games;
    
    cin.ignore();
    
    string match_played;
    
    while(number_of_games--)
    {
        getline(cin, match_played);
        
        search_for_team(match_played, team, number_of_teams);
    }
    
    sort(team, team + number_of_teams, compare);
}


void Football_input()
{
    fast
    
    string Team_name;
    getline(cin, Team_name);
    
    if(Team_name.empty()) getline(cin, Team_name);
    
    int number_of_teams;
    cin >> number_of_teams;
    
    cin.ignore();
    
    F_team team[number_of_teams]; 
    
    for(int i = 0; i < number_of_teams; i++)
    {
        getline(cin, team[i].name);
    }
    
    processesing(team, number_of_teams);
    
    output_ans(team, number_of_teams, Team_name);
}


int main() {
    fast
    
    int t;
    cin >> t;
    
    cin.ignore();
    
    while(t--) {
        Football_input();
        
        if(t > 0) cout << endl;
    }
    
    return 0;
}
