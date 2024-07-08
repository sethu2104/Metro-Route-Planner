#include <bits/stdc++.h>
using namespace std;

class Metro_graph
{
private:
    unordered_map<string, unordered_map<string, float>> adjList;

public:
    void createStation(const string &node)
    {
        adjList[node] = unordered_map<string, float>();
    }

    void createPath(const string &src, const string &dest, float weight)
    {
        adjList[src][dest] = weight;
        adjList[dest][src] = weight;
    }

    void display_Stations()
    {
        cout << "List of all stations:" << endl;
        int i = 1;
        for (const auto &node : adjList)
        {

            cout << i << "->" << node.first << endl;
            i++;
        }
        cout << endl;
    }

    void display_Metro_Map()
    {
        cout << "Metro Map:" << endl;
        for (const auto &node : adjList)
        {
            cout << node.first << " -> ";
            for (const auto &neighbour : node.second)
            {
                cout << neighbour.first << ",";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool is_Station_Present(const string &node)
    {
        return adjList.find(node) != adjList.end();
    }

    pair<float, vector<string>> dijkstra(const string &source, const string &destination)
    {
        unordered_map<string, float> distance;
        map<string, string> parent;
        parent[source] = source;
        for (const auto &vertex : adjList)
        {
            distance[vertex.first] = INT_MAX;
        }
        distance[source] = 0.0;

        priority_queue<pair<float, string>, vector<pair<float, string>>, greater<pair<float, string>>> pq;
        pq.push({0.0, source});

        while (!pq.empty())
        {
            string curr = pq.top().second;
            float dis = pq.top().first;
            // cout << curr << " " << dis << endl;
            pq.pop();

            for (const auto &neighbor : adjList[curr])
            {
                string next = neighbor.first;
                float weight = neighbor.second;

                if (dis + weight < distance[next])
                {
                    distance[next] = distance[curr] + weight;
                    pq.push({distance[next], next});
                    parent[next] = curr;
                }
            }
        }
        vector<string> parent_result;
        string station = destination;
        while (parent[station] != station)
        {
            parent_result.push_back(station);
            station = parent[station];
        }
        parent_result.push_back(source);
        reverse(parent_result.begin(), parent_result.end());

        return {(float)distance[destination], parent_result};
    }

    vector<string> get_Interchanges(int distance)
    {
        vector<string> interchanges;
        int numInterchanges = 0;
        for (const auto &vertex : adjList)
        {
            if (vertex.second.size() > 2)
            {
                numInterchanges++;
            }
        }
        interchanges.push_back(to_string(distance));
        interchanges.push_back(to_string(numInterchanges));
        for (const auto &vertex : adjList)
        {
            if (vertex.second.size() > 2)
            {
                interchanges.push_back(vertex.first);
            }
        }
        return interchanges;
    }
};

int main()
{
    Metro_graph hyderabad_metro;
    unordered_map<string, vector<string>> metro_line_color;

    hyderabad_metro.createStation("Raidurg");
    metro_line_color["Raidurg"] = {"blue"};
    hyderabad_metro.createStation("Hitec city");
    metro_line_color["Hitec city"] = {"blue"};
    hyderabad_metro.createStation("Durgam Cheruvu");
    metro_line_color["Durgam Cheruvu"] = {"blue"};
    hyderabad_metro.createStation("Pedama Temple");
    metro_line_color["Pedama Temple"] = {"blue"};
    hyderabad_metro.createStation("Jublie Hills RdNo 5");
    metro_line_color["Jublie Hills RdNo 5"] = {"blue"};
    hyderabad_metro.createStation("Yusufguda");
    metro_line_color["Yusufguda"] = {"blue"};
    hyderabad_metro.createStation("Madhura Nagar");
    metro_line_color["Madhura Nagar"] = {"blue"};
    hyderabad_metro.createStation("Ameerpet");
    metro_line_color["Ameerpet"] = {"blue", "red"};
    hyderabad_metro.createStation("Begumpet");
    metro_line_color["Begumpet"] = {"blue"};
    hyderabad_metro.createStation("Prakash Nagar");
    metro_line_color["Prakash Nagar"] = {"blue"};
    hyderabad_metro.createStation("Rasoolpur");
    metro_line_color["Rasoolpur"] = {"blue"};
    hyderabad_metro.createStation("Paradise");
    metro_line_color["Paradise"] = {"blue"};
    hyderabad_metro.createStation("Parade Ground");
    metro_line_color["Parade Ground"] = {"blue", "green"};
    hyderabad_metro.createStation("Secunderabad East");
    metro_line_color["Secunderabad East"] = {"blue"};
    hyderabad_metro.createStation("Mettuguda");
    metro_line_color["Mettuguda"] = {"blue"};
    hyderabad_metro.createStation("Tarnaka");
    metro_line_color["Tarnaka"] = {"blue"};
    hyderabad_metro.createStation("Habsiguda");
    metro_line_color["Habsiguda"] = {"blue"};
    hyderabad_metro.createStation("Uppal Stadium");
    metro_line_color["Uppal Stadium"] = {"blue"};
    hyderabad_metro.createStation("Nagole");
    metro_line_color["Nagole"] = {"blue"};
    hyderabad_metro.createStation("Miyapur");
    metro_line_color["Miyapur"] = {"red"};
    hyderabad_metro.createStation("Kukatpally");
    metro_line_color["Kukatpally"] = {"red"};
    hyderabad_metro.createStation("Moosapet");
    metro_line_color["Moosapet"] = {"red"};
    hyderabad_metro.createStation("Erragada");
    metro_line_color["Erragada"] = {"red"};
    hyderabad_metro.createStation("Panjagutta");
    metro_line_color["Panjagutta"] = {"red"};
    hyderabad_metro.createStation("Khairatabad");
    metro_line_color["Khairatabad"] = {"red"};
    hyderabad_metro.createStation("Lakdi-ka-pul");
    metro_line_color["Lakdi-ka-pul"] = {"red"};
    hyderabad_metro.createStation("Assembly");
    metro_line_color["Assembly"] = {"red"};
    hyderabad_metro.createStation("Gandhi Bhavan");
    metro_line_color["Gandhi Bhavan"] = {"red"};
    hyderabad_metro.createStation("Osmania Medical College");
    metro_line_color["Osmania Medical College"] = {"red"};
    hyderabad_metro.createStation("Musarambagh");
    metro_line_color["Musarambagh"] = {"red"};
    hyderabad_metro.createStation("Dilshuknagar");
    metro_line_color["Dilshuknagar"] = {"red"};
    hyderabad_metro.createStation("Victoria Memorial");
    metro_line_color["Victoria Memorial"] = {"red"};
    hyderabad_metro.createStation("LB Nagar");
    metro_line_color["LB Nagar"] = {"red"};
    hyderabad_metro.createStation("Secunderabad West");
    metro_line_color["Secunderabad West"] = {"green"};
    hyderabad_metro.createStation("Gandhi Hospital");
    metro_line_color["Gandhi Hospital"] = {"green"};
    hyderabad_metro.createStation("RTC X Roads");
    metro_line_color["RTC X Roads"] = {"green"};
    hyderabad_metro.createStation("Sultan Bazar");
    metro_line_color["Sultan Bazar"] = {"green"};
    hyderabad_metro.createStation("MG Bus Station");
    metro_line_color["MG Bus Station"] = {"green", "red"};
    hyderabad_metro.createStation("Salarjung Museum");
    metro_line_color["Salarjung Museum"] = {"green"};
    hyderabad_metro.createStation("Charminar");
    metro_line_color["Charminar"] = {"green"};
    hyderabad_metro.createStation("Faluknama");
    metro_line_color["Faluknama"] = {"green"};

    hyderabad_metro.createPath("Raidurg", "Hitec city", 1.5);
    hyderabad_metro.createPath("Hitec city", "Durgam Cheruvu", 0.9);
    hyderabad_metro.createPath("Durgam Cheruvu", "Pedama Temple", 2.0);
    hyderabad_metro.createPath("Pedama Temple", "Jublie Hills RdNo 5", 2.1);
    hyderabad_metro.createPath("Jublie Hills RdNo 5", "Yusufguda", 0.9);
    hyderabad_metro.createPath("Yusufguda", "Madhura Nagar", 1.5);
    hyderabad_metro.createPath("Madhura Nagar", "Ameerpet", 0.7);
    hyderabad_metro.createPath("Ameerpet", "Begumpet", 1.6);
    hyderabad_metro.createPath("Ameerpet", "Erragada", 2.7);
    hyderabad_metro.createPath("Ameerpet", "Panjagutta", 1.1);
    hyderabad_metro.createPath("Begumpet", "Prakash Nagar", 1.4);
    hyderabad_metro.createPath("Prakash Nagar", "Rasoolpur", 1.2);
    hyderabad_metro.createPath("Rasoolpur", "Paradise", 1.0);
    hyderabad_metro.createPath("Paradise", "Parade Ground", 1.2);
    hyderabad_metro.createPath("Parade Ground", "Secunderabad East", 1.6);
    hyderabad_metro.createPath("Parade Ground", "Secunderabad West", 0.35);
    hyderabad_metro.createPath("Secunderabad East", "Mettuguda", 1.9);
    hyderabad_metro.createPath("Mettuguda", "Tarnaka", 1.2);
    hyderabad_metro.createPath("Tarnaka", "Habsiguda", 1.6);
    hyderabad_metro.createPath("Habsiguda", "Uppal Stadium", 2.0);
    hyderabad_metro.createPath("Uppal Stadium", "Nagole", 2.1);
    hyderabad_metro.createPath("Miyapur", "Kukatpally", 6.2);
    hyderabad_metro.createPath("Kukatpally", "Moosapet", 5.0);
    hyderabad_metro.createPath("Moosapet", "Erragada", 1.8);
    hyderabad_metro.createPath("Erragada", "Panjagutta", 3.7);
    hyderabad_metro.createPath("Panjagutta", "Khairatabad", 2.2);
    hyderabad_metro.createPath("Khairatabad", "Lakdi-ka-pul", 1.1);
    hyderabad_metro.createPath("Lakdi-ka-pul", "Assembly", 1.0);
    hyderabad_metro.createPath("Assembly", "Gandhi Bhavan", 1.4);
    hyderabad_metro.createPath("Gandhi Bhavan", "Osmania Medical College", 0.9);

    hyderabad_metro.createPath("Musarambagh", "Dilshuknagar", 1.5);
    hyderabad_metro.createPath("Dilshuknagar", "Victoria Memorial", 2.3);
    hyderabad_metro.createPath("Victoria Memorial", "LB Nagar", 1.4);
    hyderabad_metro.createPath("Secunderabad West", "Gandhi Hospital", 1.3);
    hyderabad_metro.createPath("Gandhi Hospital", "RTC X Roads", 1.2);
    hyderabad_metro.createPath("RTC X Roads", "Sultan Bazar", 2.7);
    hyderabad_metro.createPath("MG Bus Station", "Musarambagh", 3.0);
    hyderabad_metro.createPath("Osmania Medical College", "MG Bus Station", 0.6);
    hyderabad_metro.createPath("Sultan Bazar", "MG Bus Station", 1.1);
    hyderabad_metro.createPath("MG Bus Station", "Salarjung Museum", 1);
    hyderabad_metro.createPath("Salarjung Museum", "Charminar", 1.5);
    hyderabad_metro.createPath("Charminar", "Faluknama", 3.5);

    cout << "WELCOME TO METRO HOME PAGE" << endl;

    while (true)
    {
        cout << "FOLLOWING  SERVICES  ARE PROVIDED ON THIS PAGE" << endl;
        cout << "1. LIST ALL THE STATIONS IN THE MAP" << endl;
        cout << "2. SHOW THE METRO MAP" << endl;
        cout << "3. GET SHORTEST DISTANCE FROM A 'SOURCE' STATION TO 'DESTINATION' STATION, CORRESPONDING TIME TAKEN & THE TICKET FARE FOR YOUR RIDE" << endl;

        cout << "4. GET SHORTEST PATH (DISTANCE WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << endl;
        cout << "5. EXIT THE MENU" << endl;
        cout << "ENTER YOUR CHOICE FROM THE ABOVE LIST (1 to 5): " << endl;
        int choice = -1;
        cin >> choice;
        cout << "############# *WELCOME* ####################" << endl;

        if (choice == 5)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            hyderabad_metro.display_Stations();
            break;

        case 2:
            hyderabad_metro.display_Metro_Map();
            break;

        case 3:
        {
            string source, destination;
            cout << "Enter source station: ";
            cin.ignore();
            getline(cin, source);
            cout << "Enter destination station: ";
            getline(cin, destination);

            if (hyderabad_metro.is_Station_Present(source) && hyderabad_metro.is_Station_Present(destination))
            {

                float distance = hyderabad_metro.dijkstra(source, destination).first;
                cout << " Shortest distance from " << source << " to " << destination << " is: " << distance << " km" << endl;
                float time = 1.8 * distance;
                cout << " Shortest time to reach from " << source << " to " << destination << " is: " << time << " minutes" << endl;
                int price;
                if (distance >= 0 && distance <= 2)
                {
                    price = 10;
                }
                else if (distance >= 2 && distance < 4)
                {
                    price = 15;
                }
                else if (distance >= 4 && distance < 6)
                {
                    price = 25;
                }
                else if (distance >= 6 && distance < 8)
                {
                    price = 30;
                }
                else if (distance >= 8 && distance < 10)
                {
                    price = 35;
                }
                else if (distance >= 10 && distance < 14)
                {
                    price = 40;
                }
                else if (distance >= 14 && distance < 18)
                {
                    price = 45;
                }
                else if (distance >= 18 && distance < 22)
                {
                    price = 50;
                }
                else if (distance >= 22 && distance < 26)
                {
                    price = 55;
                }
                else
                {
                    price = 60;
                }
                cout << "The minimum fare to reach from " << source << " to " << destination << " is  Rs. " << price << endl;
            }
            else
            {
                cout << "Invalid source or destination station" << endl;
            }
        }
        break;

        case 4:
        {
            string source, destination;
            cout << "Enter source station: " << endl;
            cin.ignore();
            getline(cin, source);
            cout << "Enter destination station: " << endl;
            getline(cin, destination);

            if (hyderabad_metro.is_Station_Present(source) && hyderabad_metro.is_Station_Present(destination))
            {
                auto it = hyderabad_metro.dijkstra(source, destination);

                float distance = it.first;
                vector<string> parent_result = it.second;
                vector<string> present_color;

                vector<string> interchange_station;
                int n = parent_result.size();
                for (int i = 0; i < n; i++)
                {
                    string node = parent_result[i];

                    if (metro_line_color[node].size() > 1)
                    {

                        if (i - 1 >= 0 && i + 1 < n)
                        {
                            auto prev_line = metro_line_color[parent_result[i - 1]][0];
                            auto next_line = metro_line_color[parent_result[i + 1]][0];
                            if (prev_line != next_line)
                            {
                                interchange_station.push_back(node);
                            }
                        }
                    }
                }

                cout << "Shortest path (distance wise) from " << source << " to " << destination << " is: " << (float)distance << " km" << endl;

                cout << "No.of interchange stations are " << interchange_station.size() << endl;
                for (auto &x : interchange_station)
                {
                    cout << x << " ";
                }
                cout << endl;
            }
            else
            {
                cout << "Invalid source or destination station" << endl;
            }
        }
        break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << "############# *WELCOME* ####################" << endl;
        }
    return 0;
}