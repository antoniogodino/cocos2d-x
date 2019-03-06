//
//  InfiniteParallax.hpp
//  DemoJuego
//
//  Created by Luis Fernando de Mingo López on 5/3/19.
//

#ifndef InfiniteParallax_hpp
#define InfiniteParallax_hpp
USING_NS_CC;

class InfiniteParallaxNode : public ParallaxNode
{
public:
    static InfiniteParallaxNode* create();
    void updatePosition();
};

#endif /* InfiniteParallax_hpp */
