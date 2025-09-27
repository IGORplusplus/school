class Node:
    def __init__(self, name):
        self.name = name
        self.transitions = {}

    def add_transition(self, input_symbol, next_node):
        self.transitions[input_symbol] = next_node

    def get_next(self, input_symbol):
        return self.transitions.get(input_symbol, None)

class FiniteStateMachine:
    def __init__(self, start_node):
        self.current_node = start_node

    def process(self, input_symbol):
        next_node = self.current_node.get_next(input_symbol)
        if next_node:
            print(f"Transition: {self.current_node.name} --({input_symbol})--> {next_node.name}")
            self.current_node = next_node
        else:
            print(f"No transition found for input '{input_symbol}' in state '{self.current_node.name}'.")

    def run(self, inputs):
        for input_symbol in inputs:
            self.process(input_symbol)

# Example usage
if __name__ == "__main__":
    # Create states
    idle = Node("Idle")
    working = Node("Working")
    finished = Node("Finished")

    # Define transitions
    idle.add_transition('start', working)
    working.add_transition('complete', finished)
    finished.add_transition('reset', idle)

    # Create FSM starting at 'Idle'
    fsm = FiniteStateMachine(idle)

    # Simulate input sequence
    input_sequence = ['start', 'complete', 'start', 'reset', 'complete', 'start']
    fsm.run(input_sequence)
