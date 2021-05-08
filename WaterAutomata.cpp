#include "WaterAutomata.hpp"

WaterAutomata::WaterAutomata(Grid& grid) : grid(grid) {}

void WaterAutomata::Move() {
    Grid grid_tmp = grid;
    for (int i = grid.GridSize().y-1; i >=0; i--) {
        for (int j = 0; j < grid.GridSize().x; j++) {
                if(grid[i][j].type==CellType::WATER && grid[i][j].cnt>100)
                    grid[i][j].cnt=100;
            if (grid[i][j].type == CellType::WATER ){
                    //waterfall
                    bool wf=0;
                    if(i != grid.GridSize().y-1 && grid[i+1][j].cnt<100)
                        WaterFall(i, j, grid_tmp, &wf);

                    //rastekaetsa voda
                    if((i != grid.GridSize().y-1 && grid[i+1][j].type!=CellType::AIR  &&
                        grid[i][j].cnt>=12 && wf==0) || (i == grid.GridSize().y-1) && wf==0  && grid[i][j].cnt>=12)
                    {


                        if(j>0 && grid[i][j-1].cnt<grid[i][j].cnt ||
                           j<grid.GridSize().x-1 && grid[i][j+1].cnt<grid[i][j].cnt)
                        {
                            Spread(i,j,grid_tmp);

                        }

                    }
            }
        }
    }
grid = grid_tmp;
int x=0;
for (int i = grid.GridSize().y-1; i >=0; i--) {
        for (int j = 0; j < grid.GridSize().x; j++) {
                x+=grid[i][j].cnt;
        }
}
//std::cout<<x<<"\n";

}

void WaterAutomata::WaterFall(int i, int j, Grid& grid_tmp, bool *wf)
{
    if(i != grid.GridSize().y-1 && grid[i+1][j].cnt<100)
                    {
                        int x=grid[i+1][j].cnt+grid[i][j].cnt;
                        if(x<=100)
                        {
                            grid_tmp[i+1][j].cnt=x%101;
                            grid_tmp[i+1][j].type=CellType::WATER;
                            grid_tmp[i][j].cnt=0;
                            grid_tmp[i][j].type=CellType::AIR;
                        }
                        else
                        {
                            grid_tmp[i+1][j].cnt=100;
                            grid_tmp[i+1][j].type=CellType::WATER;
                            grid_tmp[i][j].cnt=(x-100)%101;
                        }
                        *wf=1;
                        grid[i][j]=grid_tmp[i][j];
                        grid[i+1][j]=grid_tmp[i+1][j];
                        if(grid_tmp[i][j].cnt<100)
                                Spread(i,j,grid_tmp);
                    }
}

void WaterAutomata::Spread(int i, int j, Grid& grid_tmp)
{
    if(j>0 && grid[i][j].cnt-grid[i][j-1].cnt>1 &&
    j<grid.GridSize().x-1 && grid[i][j].cnt-grid[i][j+1].cnt>1)
    {
        grid_tmp[i][j+1].type=CellType::WATER;
        grid_tmp[i][j-1].type=CellType::WATER;
        int x=grid[i][j].cnt+grid[i][j-1].cnt+grid[i][j+1].cnt;
        grid_tmp[i][j+1].cnt=x/3;
        grid_tmp[i][j].cnt=x-x/3-x/3;
        grid_tmp[i][j-1].cnt=x/3;
        grid[i][j]=grid_tmp[i][j];
        grid[i][j+1]=grid_tmp[i][j+1];
        grid[i][j-1]=grid_tmp[i][j-1];
        if(i != grid.GridSize().y-1 && grid[i+1][j].cnt<100)
        {
            WaterFall(i,j-1,grid_tmp,0);
            WaterFall(i,j+1,grid_tmp,0);
        }

        //j-=2;
        }
        //else
        if(j>0 && grid[i][j].cnt-grid[i][j-1].cnt>1)
        {
            int x=grid[i][j].cnt+grid[i][j-1].cnt;
            grid_tmp[i][j].cnt=x-x/2;
            grid_tmp[i][j-1].type=CellType::WATER;
            grid_tmp[i][j-1].cnt=x/2;
            grid[i][j]=grid_tmp[i][j];
            grid[i][j-1]=grid_tmp[i][j-1];
            if(i != grid.GridSize().y-1 && grid[i+1][j].cnt<100)
                WaterFall(i,j-1,grid_tmp,0);
            //j-=2;
        }
        //else
        if(j<grid.GridSize().x-1 && grid[i][j].cnt-grid[i][j+1].cnt>1)
        {
            grid_tmp[i][j+1].type = CellType::WATER;
            int x=(grid[i][j+1].cnt+grid[i][j].cnt);
            grid_tmp[i][j+1].cnt=x/2;
            grid_tmp[i][j].cnt=x-x/2;
            grid[i][j]=grid_tmp[i][j];
            grid[i][j+1]=grid_tmp[i][j+1];
            if(i != grid.GridSize().y-1 && grid[i+1][j].cnt<100)
                WaterFall(i,j+1,grid_tmp,0);
        }

}

void WaterAutomata::Tick() {
    Move();
}

void WaterAutomata::Render(sf::RenderWindow& l_window) {
    // Leave it blank for now
}
