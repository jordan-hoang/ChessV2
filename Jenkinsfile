pipeline {
  
    agent any
    stages{
        
        stage("build"){
            steps{
                echo "building the application..."
                ls;
                mkdir cmake-build-debug;
                cd cmake-build-debug;
                cmake ../;
                make;
                
            }
        }
        
        stage("test"){
            steps{
                echo "testing the application..."



            }
        }


        stage("deploy"){
            steps{
                echo "Deploying the application... (There is no deploy but this is here just for testing...)"
            }
        }
    
    }

}
