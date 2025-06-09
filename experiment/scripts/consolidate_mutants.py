import csv
import os
import sys
from collections import defaultdict

def read_operators_list(operators_file):
    """Read the list of operators from the unit-operators-list.txt file."""
    operators = []
    try:
        with open(operators_file, 'r') as f:
            for line in f:
                operator = line.strip()
                if operator:
                    operators.append(operator)
    except FileNotFoundError:
        print(f"Error: Operators file '{operators_file}' not found.")
        sys.exit(1)
    return operators

def read_programs_list(files_txt):
    """Read the list of program names from files.txt."""
    programs = []
    try:
        with open(files_txt, 'r') as f:
            for line in f:
                program = line.strip()
                if program:
                    programs.append(program)
    except FileNotFoundError:
        print(f"Error: Programs file '{files_txt}' not found.")
        sys.exit(1)
    return programs

def process_program_csv(csv_path):
    """Process a single CSV file and return the data as a dictionary."""
    data = {}
    try:
        with open(csv_path, 'r') as f:
            reader = csv.DictReader(f)
            for row in reader:
                operator = row['Operator']
                if operator != 'Total':  # Skip the total row
                    data[operator] = {
                        'NON_EQ': int(row['NON_EQ']),
                        'EQ': int(row['EQ']),
                        'TOTAL': int(row['TOTAL'])
                    }
    except FileNotFoundError:
        print(f"Warning: CSV file '{csv_path}' not found. Skipping...")
        return {}
    except (ValueError, KeyError) as e:
        print(f"Warning: Error reading CSV file '{csv_path}': {e}. Skipping...")
        return {}
    return data

def sum_all_data(programs_dir, programs_list, operators_list):
    """Sum data from all program CSV files."""
    # Initialize sums for all operators
    total_data = {}
    for operator in operators_list:
        total_data[operator] = {'NON_EQ': 0, 'EQ': 0, 'TOTAL': 0}
    
    processed_files = 0
    
    for program in programs_list:
        csv_path = os.path.join(programs_dir, program, 'number-of-mutants-per-operator.csv')
        program_data = process_program_csv(csv_path)
        
        if program_data:
            processed_files += 1
            # Add data from this program to totals
            for operator, values in program_data.items():
                if operator in total_data:
                    total_data[operator]['NON_EQ'] += values['NON_EQ']
                    total_data[operator]['EQ'] += values['EQ']
                    total_data[operator]['TOTAL'] += values['TOTAL']
                else:
                    print(f"Warning: Unknown operator '{operator}' found in {program}")
    
    print(f"Successfully processed {processed_files} out of {len(programs_list)} programs.")
    return total_data

def write_output_csv(output_file, total_data, operators_list):
    """Write the summed data to a CSV file."""
    try:
        with open(output_file, 'w', newline='') as f:
            writer = csv.writer(f)
            
            # Write header
            writer.writerow(['Operator', 'NON_EQ', 'EQ', 'TOTAL'])
            
            # Write data for each operator
            grand_total_non_eq = 0
            grand_total_eq = 0
            grand_total_total = 0
            
            for operator in operators_list:
                data = total_data[operator]
                writer.writerow([operator, data['NON_EQ'], data['EQ'], data['TOTAL']])
                grand_total_non_eq += data['NON_EQ']
                grand_total_eq += data['EQ']
                grand_total_total += data['TOTAL']
            
            # Write total row
            writer.writerow(['Total', grand_total_non_eq, grand_total_eq, grand_total_total])
            
        print(f"Output written to '{output_file}'")
        
    except IOError as e:
        print(f"Error writing output file '{output_file}': {e}")
        sys.exit(1)

def main():
    """Main function to orchestrate the data processing."""
    if len(sys.argv) != 4:
        print("Usage: python script.py <programs_directory> <files.txt> <unit-operators-list.txt>")
        print("Example: python script.py ./programs files.txt unit-operators-list.txt")
        sys.exit(1)
    
    programs_dir = sys.argv[1]
    files_txt = sys.argv[2]
    operators_file = sys.argv[3]
    output_file = "consolidated-mutants-per-operator.csv"
    
    # Validate that the programs directory exists
    if not os.path.isdir(programs_dir):
        print(f"Error: Directory '{programs_dir}' does not exist.")
        sys.exit(1)
    
    print("Reading operators list...")
    operators_list = read_operators_list(operators_file)
    print(f"Found {len(operators_list)} operators.")
    
    print("Reading programs list...")
    programs_list = read_programs_list(files_txt)
    print(f"Found {len(programs_list)} programs.")
    
    print("Processing CSV files...")
    total_data = sum_all_data(programs_dir, programs_list, operators_list)
    
    print("Writing consolidated results...")
    write_output_csv(output_file, total_data, operators_list)
    
    print("Processing complete!")

if __name__ == "__main__":
    main()

