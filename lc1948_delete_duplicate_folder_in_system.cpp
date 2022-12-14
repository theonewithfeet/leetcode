// https://leetcode.com/problems/delete-duplicate-folders-in-system/

class Solution {
    struct Node {
        map<string,Node*> child;
        bool duplicate=false;
    };
        
    void build(Node* root,vector<vector<string>>& paths) {
        for (auto& dirs : paths) {
            Node* node=root;
            for (auto& dir : dirs) {
                if (node->child.count(dir) == 0) 
                    node->child[dir] = new Node;
                node = node->child[dir];
            }
        }
    }
    
    string prune(Node* node,unordered_map<string,vector<Node*>>& subdirs) {
        if (node->child.size() == 0) 
            return "";
        
        string subdir("(");
        for (auto& [dir,child] : node->child) 
            subdir += dir + prune(child,subdirs);        
        subdir += ")";
        
        auto& nodes = subdirs[subdir];
        nodes.push_back(node);
        
        if (nodes.size() > 1) {
            nodes.front()->duplicate = true;
            nodes.back()->duplicate = true;
        }
        return subdir;
    }

    void gather(Node *node,vector<string>& path,vector<vector<string>>& result) {
        if (node->duplicate == false) {
            if (path.size())
                result.push_back(path);
            for (auto& [dir, child] : node->child) {
                path.push_back(dir);
                gather(child,path,result);
                path.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node root;
        build(&root,paths); 
        
        unordered_map<string,vector<Node*>> subdirs;
        prune(&root,subdirs);
        
        vector<vector<string>> result;
        vector<string> path;        
        gather(&root,path,result);
        
        return result;
    }
};