#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, 
float end_x, float end_y): m_Model(model) {

    // inputs to percentage:
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;

    start_node = &m_Model.FindClosestNode(start_x,start_y);
    end_node   = &m_Model.FindClosestNode(end_x,end_y);
}

float RoutePlanner::CalculateHValue(RouteModel::Node const *node) {

    return node->distance(*end_node);
}

void RoutePlanner::AddNeighbors(RouteModel::Node *current_node) {
    
    current_node->FindNeighbors();
    
	for(auto neighbor : current_node->neighbors)
	{
		neighbor->parent = current_node;
		neighbor->g_value = current_node->g_value + current_node->distance(*neighbor);
		
        neighbor->h_value = CalculateHValue(neighbor);

		open_list.emplace_back(neighbor);
		neighbor->visited = true;
	}
}


RouteModel::Node *RoutePlanner::NextNode() {
    
    std::sort(open_list.begin(),open_list.end(),
        [](const auto & A, const auto & B){
		    return (A->h_value + A->g_value) < (B->h_value + B->g_value);
	});

    RouteModel::Node* PunteroMenorValor = open_list.front();

    open_list.erase(open_list.begin());
    
    return PunteroMenorValor;
}

std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node) {

    distance = 0.0f;
    std::vector<RouteModel::Node> path_found;

    while(current_node->parent != nullptr)
	{   

        path_found.insert(path_found.begin(), *current_node);
        distance += current_node->distance(*(current_node->parent));
        current_node = current_node->parent;
    }

    path_found.insert(path_found.begin(), *current_node);
    
    distance *= m_Model.MetricScale();
    return path_found;
}
	

void RoutePlanner::AStarSearch() {
    RouteModel::Node *current_node = nullptr;

    current_node = start_node;
	start_node->visited = true;
    
	open_list.emplace_back(current_node);

    do{
        AddNeighbors(current_node);
	    current_node = NextNode();
	}while((open_list.size() > 0)&&!((end_node->x==current_node->x)&&(end_node->y==current_node->y)));

    m_Model.path = ConstructFinalPath(end_node);
}