#include <bits/stdc++.h>

const size_t SMALL_SIZE_THRESHOLD = 100000;

struct Node;

enum class node_type {
    dir,
    file
};

typedef std::string node_name;
typedef node_type node_type;
typedef size_t node_size;
typedef std::shared_ptr<Node> node_ptr;
typedef std::map<node_name, node_ptr> node_kids;
typedef size_t Depth;

struct Node {
    node_name name;
    node_type type;
    node_size size;
    node_ptr parent;
    node_kids kids;

    Node() : name(""), type(node_type::dir), size(0), parent(nullptr), kids() {}
    Node(node_name name, node_type type, node_size size, node_ptr parent)
        : name(name), type(type), size(size), parent(parent), kids() {}
};

node_size dir_size(node_ptr node) {
    if (node->type == node_type::file) {
        return node->size;
    }

    node_size size = 0;

    for (auto [kid_name, kid] : node->kids) {
        size += dir_size(kid);
    }

    return size;
}

node_size parse_size(std::string string) {
    if (string.empty()) return 0;

    return std::stoull(string);
}

node_size calculate_total_small_dir_size(node_ptr node) {
    node_size size = dir_size(node);

    if (size > SMALL_SIZE_THRESHOLD) {
        size = 0;
    }

    for (auto [kid_name, kid] : node->kids) {
        if (kid->type == node_type::dir) {
            size += calculate_total_small_dir_size(kid);
        }
    }

    return size;
}

void add_kid(node_ptr parent, node_name name, node_type type, node_size size) {
    node_ptr child = std::make_shared<Node>(name, type, size, parent);
    parent->kids[name] = child;
}

std::tuple<node_ptr, node_ptr> parse_command(std::string command, node_ptr current_node, node_ptr root) {
    std::string function;
    std::stringstream ss(command);

    ss >> function >> function;

    if (function == "cd") {
        std::string location;
        ss >> location;

        if (location == "/") {
            return std::tie(root->parent, root);
        }

        if (location == "..") {
            return std::tie(current_node->parent->parent, current_node->parent);
        }

        return std::tie(current_node, current_node->kids[location]);
    }

    if (function == "ls") {
        std::string size_or_type;
        node_name name;
        while (std::cin.peek() != EOF && std::cin.peek() != '$') {
            std::cin >> size_or_type >> name;

            if (size_or_type == "dir") {
                add_kid(current_node, name, node_type::dir, 0);
            } else {
                add_kid(current_node, name, node_type::file, parse_size(size_or_type));
            }

            std::cin.ignore(1);
        }
    }

    return std::tie(current_node->parent, current_node);
}

int main() {
    std::string input_string;
    node_ptr prev_node = std::make_shared<Node>();
    node_ptr current_node = std::make_shared<Node>();

    node_ptr root = std::make_shared<Node>("/", node_type::dir, 0, nullptr);


    while (std::getline(std::cin, input_string)) {
        // record the node we are currently in for the next iteration
        std::tie(prev_node, current_node) = parse_command(input_string, current_node, root);
    }

    std::cout << calculate_total_small_dir_size(root) << std::endl;

    return 0;
}