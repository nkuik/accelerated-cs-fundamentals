/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"
#include "Stack.h"
#include "uiuc/Cube.h"
#include "uiuc/HSLAPixel.h"

#include <iostream>
using std::cout;
using std::endl;

std::string stack_to_string(Stack & stack) {
  std::ostringstream stack_stream;
  stack_stream << stack;
  std::string stack_string = stack_stream.str();
  
  return stack_string;
}

void move_cube(Stack & stack_to_move_from, Stack & stack_to_move_to) {
  std::cout << "Stack remove block from is: " << stack_to_move_from << std::endl;
  std::cout << "Stack move the block to is: " << stack_to_move_to << std::endl;
  
  Cube cube = stack_to_move_from.removeTop();
  stack_to_move_to.push_back(cube);
}

void find_and_move_cube(Stack & stack1, Stack & stack2) {
  std::cout << "Stacks to compare are: " << stack1 << "And: " << stack2  << std::endl;
  
  Stack stack_to_remove;
  if (stack1.size() == 0 || stack2.size() == 0) {
    if (stack1.size() == 0) {
      stack_to_remove = stack2;
    }
   if (stack2.size() == 0) {
      stack_to_remove = stack1;
    }
  }
  else {
    double first_length = stack1.peekTop().getLength();
    std::cout << "First length is: " << first_length  << std::endl;
    double second_length = stack2.peekTop().getLength();
    std::cout << "Second length is: " << second_length  << std::endl;
    
    if (first_length > second_length) {
      stack_to_remove = stack2;
    }
    else {
      stack_to_remove = stack1;
    }
  }
  
  std::cout << "Stack to remove top is: " << stack_to_remove  << std::endl;
  
  if (stack_to_string(stack_to_remove) == stack_to_string(stack1)) {
    move_cube(stack1, stack2);
  }
  else {
    move_cube(stack2, stack1);
  }
}

void Game::run_pattern() {
  find_and_move_cube(stacks_[0], stacks_[1]);
  find_and_move_cube(stacks_[0], stacks_[2]);
  find_and_move_cube(stacks_[1], stacks_[2]);
}
// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)
void Game::solve() {
  // Prints out the state of the game:
  std::string winning_stack_string; 
  winning_stack_string = stack_to_string(winning_stack);
  std::cout << "Winning string is: " << winning_stack_string << std::endl;
  
  std::string last_stack_string;
  last_stack_string = stack_to_string(stacks_[2]);
  std::cout << "Last stack string is: " << last_stack_string << std::endl;
  while ( last_stack_string != winning_stack_string ) {
    cout << *this << endl;

    run_pattern();

    last_stack_string = stack_to_string(stacks_[2]);;
    std::cout << "Last string is: " << last_stack_string << std::endl;
    std::cout << "Strings are equal: " << (winning_stack_string == last_stack_string) << std::endl; 
  };

}

// Default constructor to create the initial state:
Game::Game() {
  // Create the three empty stacks:
  for (int i = 0; i < 3; i++) {
    Stack stackOfCubes;
    stacks_.push_back( stackOfCubes );
  }

  // Create the four cubes, placing each on the [0]th stack:
  Cube blue(4, uiuc::HSLAPixel::BLUE);
  stacks_[0].push_back(blue);

  Cube orange(3, uiuc::HSLAPixel::ORANGE);
  stacks_[0].push_back(orange);

  Cube purple(2, uiuc::HSLAPixel::PURPLE);
  stacks_[0].push_back(purple);

  Cube yellow(1, uiuc::HSLAPixel::YELLOW);
  stacks_[0].push_back(yellow);
  
  winning_stack.push_back(blue);
  winning_stack.push_back(orange);
  winning_stack.push_back(purple);
  winning_stack.push_back(yellow);
}

std::ostream& operator<<(std::ostream & os, const Game & game) {
  for (unsigned i = 0; i < game.stacks_.size(); i++) {
    os << "Stack[" << i << "]: " << game.stacks_[i];
  }
  return os;
}
