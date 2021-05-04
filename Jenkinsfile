pipeline {
  
    agent any
    stages{
        
        stage("build"){
            steps{
              
                cmakeBuild(
                  installation: 'InSearchPath'
                )
                sh "ls -l"
                echo "building the application..."
                sh "cmake ./"
                sh "make"
            }
        }
        
        stage("test"){
            steps{
                echo "testing the application..."
                sh "ls -l"
                sh "./test/runAllTests"
            }
        }
        stage("deploy"){
            steps{
                echo "deploying the application..."
            }
        }
    
    }

}
