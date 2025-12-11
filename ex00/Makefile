NAME = ex00
SRC_DIR = .
OBJ_DIR = obj
DEP_DIR = deps

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -MMD

SRC = \
	${SRC_DIR}/main.cpp

OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))
DEPS = $(patsubst $(SRC_DIR)/%.cpp,$(DEP_DIR)/%.d,$(SRC))

all: $(NAME)

$(NAME): $(OBJ) Makefile | $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -MF $(DEP_DIR)/$*.d -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(DEP_DIR):
	mkdir -p $(DEP_DIR)

clean:
	rm -f $(OBJ) $(DEPS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR) $(DEP_DIR)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re