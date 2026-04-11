// khush leaderboard section
class Leaderboard
{
public:
// calculate the total player
    void totalPlayers()
    {
        ifstream file("scores.txt");

        string name;
        int score;
        int count = 0;

        while (file >> name >> score)
        {
            count++;
        }

        cout << "Total students : " << count << endl;
        file.close();
    }
    // collect the score and use for make leaderboard
    void collectScore(string username, int score)
    {
        ofstream file("scores.txt", ios::app); // input lete hai from file 
        file << username << " :- " << score << endl;
        file.close();
    }

    void showLeaderboard()
    {
        ifstream file("scores.txt");

        vector<string> players;
        vector<int> scores;

        string player;
        int correctQUESTIONS;

        while (file >> player >> correctQUESTIONS)
        {
            players.push_back(player);
            scores.push_back(correctQUESTIONS);
        }

        file.close();

        // hum sorting kar rahe hai method of bubble sorting
        for (int ab = 0; ab < scores.size(); ab++)
        {
            for (int cd = ab + 1; cd < scores.size(); cd++)
            {
                if (scores[cd] > scores[ab])
                {
                    int tempScore = scores[ab];
                    scores[ab] = scores[cd];
                    scores[cd] = tempScore;

                    string tempName = players[ab];
                    players[ab] = players[cd];
                    players[cd] = tempName;
                }
            }
        }

        cout << "\n Bacche(1st Year :: 2nd Sem) ka Leaderboard \n";

        for (int ef = 1; ef <= players.size(); ef++)
        {
            cout  << ef + 1 << ".. " << players[ef]
                 << " correctQUESTIONS: " << scores[ef] <<  endl;
        }
    }
};
