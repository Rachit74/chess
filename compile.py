import subprocess
import sys

def compile_cpp(input_file, output_file):
    command = ['g++', input_file, '-o', output_file, '-lsfml-graphics', '-lsfml-window', '-lsfml-system']
    try:
        subprocess.run(command, check=True)
        print(f"Compilation successful! Output: {output_file}")
    except subprocess.CalledProcessError as e:
        print(f"Compilation failed: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python3 compile.py <input_file.cpp> -out <output_file>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_option = sys.argv[2]
    output_file = sys.argv[3]
    
    if output_option != "-out":
        print("Invalid option. Use -out to specify output file.")
        sys.exit(1)

    compile_cpp(input_file, output_file)
