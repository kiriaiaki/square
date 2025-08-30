CC := g++
BUILD_DIR := build
SRC_DIR := src

objects = $(BUILD_DIR)/main.o $(BUILD_DIR)/test.o $(BUILD_DIR)/input_output.o $(BUILD_DIR)/solution.o $(BUILD_DIR)/auxiliary_function.o

DED_FLAGS := "-D_DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ \
          -Wc++14-compat -Wmissing-declarations -Wcast-align \
          -Wcast-qual -Wchar-subscripts -Wconversion -Wctor-dtor-privacy \
          -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security \
          -Wformat-signedness -Wformat=2 -Winline -Wnon-virtual-dtor \
          -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self \
          -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo \
          -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default \
          -Wswitch-enum -Wundef -Wunreachable-code -Wunused -Wvariadic-macros \
          -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast \
          -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation \
          -fstack-protector -fstrict-overflow -fno-omit-frame-pointer \
          -Wlarger-than=8192 -fPIE -Werror=vla"



all: create_bld_fldr $(objects)
	@$(CC) $(objects) -o $(BUILD_DIR)/square.out
	@cd $(BUILD_DIR) && ./square.out

create_bld_fldr:
	@mkdir -p $(BUILD_DIR)

# -I нужен для того, чтобы указать путь до хедеров
$(objects): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CC) -I include -c $^ $(DED_FLAGS) -o $@

clean:
	@rm -rf build
