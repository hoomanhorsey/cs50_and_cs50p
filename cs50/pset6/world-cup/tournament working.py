# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # TODO: Read teams into memory from file

    teams = []

    filename = sys.argv[1]
    with open(filename) as f:
      reader = csv.DictReader(f)
      for team in reader:
          team["rating"] = int(team["rating"])
          teams.append(team)

      #Test print

      #for team in teams:
      #      print(team)

    ## Print and access experiments.
    #for team in teams:
    #    if team["rating"] < 1000:
    #        print("Loser team, with rating less than 1000, is", team["team"])
    #print("Full dictionary, for teams[0]", teams[0])
    #print(teams[0]['team'])
    #print(teams[0]['rating'])

    counts = {}

    for i in range(N):
        winner = simulate_tournament(teams)
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1


    #with open(filename) as g:
    #  reader = csv.DictReader(g)
    #  for team in reader:
    #    team["rating"] = int(0)
        #counts = {team}
       #print(counts)
        #counts.append(team)



    # TODO: Simulate N tournaments and keep track of win counts

        #counts is a dictionary
            #cdkeys = name of teams
            #value = how many tournaments each team has won

    # TO DO - Fill counts with each key value of 'team', then also, empty value of 'wins'.
    #HOW TO DO? Can dictionaries hold a list like that?
    # This should populate the dictionariy with the list of teams.
    #for team in teams:
     #   counts = {(teams['team']): int(0)}
      #  #how do I make the item in square brackets refer to the teams from the orig list?>
     #   print(counts)

    #Loop through each team, in teams

    #for team in teams:
    #Loop through range of N (1,000) simulations
    #    for i in range(N):
    #        simulate_tournament(team)
    #Add 1 to each
            # if won tournament, wins += 1




    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO

    while len(teams) > 1:
        teams = simulate_round(teams)
    return teams[0]["team"]

#        )
 #   winners = simulate_round(teams)
  #  if len(winners) < 2:
   #     return winners
    #simulate_tournament(winners)

#or maybe?
    #winners = simulate_round(teams)
    #if len(winners) > 1:
    #    simulate_tournament(winners)
    #return winner

#while len(winners) > 1:
    #    simulate_round(teams)
    #return winner

    #winners = simulate_round(teams)
    #while len(winners) > 1:
    #    simulate_tournament(teams)
    #return winner




    #simulate_round(teams) #insert teams into simulate_round, will return half the number of winners
    #if len(winners) > 1:
    #    simulate_round(winners)
    #elif len(winners) == 1:
    #    winner = winners
    #    return winner

        #returns winner out of team [i] and team [i+1], keep tabs on that?





if __name__ == "__main__":
    main()
