# Project Requirement Spec Template

Content

- Requirement Analysis
  - Requirements
  - Using Techniques
- System Design
  - Function Module
  - Database Design
  - Interfaces Design
- Code Implementation
  - Implementation Backend
    - Build Project
    - Integrate Swagger
    - Developing Crawler with Apache Nutch
  - Implementation Frontends
- Test & Deployment
  - CD/CI
- Optimization Function
  - WeChat Notify.

### Main

### 1. Requirement Analysis

#### 1.1 Requirements

- Crawler hot content from media.
- Frontend and Backend separation.
- Timer Crawler. 

Media

- zhihu
- V2EX
- Weibo
- Douban
- Tianya
- CloudMusic

#### 1.2 Using Techniques

- Backend
  - Spring Boot 2
  - Swagger 2
  - JUnit 5
  - Apache Nutch
- Frontend
  - Vue.js
- Test & Deployment
  - Docker
  - Jenkins
- Database & Cache
  - MySQL
  - Redis

### 2. System Design

#### 2.1 Function Module

System Function

Frontend --> Backend Controller --> Cache <--> Crawler 

#### 2.2 Database Design

t_info_type

| Name | Type    | Length | NULL     | Key  | Description |
| ---- | ------- | ------ | -------- | ---- | ----------- |
| id   | varchar | 64     | not null | P    |             |
| name | varchar | 64     | not null |      |             |

t_info

| Name  | Type    | Length | NULL     | Key  | Description |
| ----- | ------- | ------ | -------- | ---- | ----------- |
| id    | varchar | 64     | not null | P    |             |
| title | varchar | 128    | not null |      |             |
| url   | varchar | 255    | not null |      |             |



#### 2.3 Interfaces Design

1\. v1/types

Method: GET

Data Type: JSON

Parameters: null

Result:

```json
{
    ret_code: 0,
    ret_msg: "success",
    data: [
        {
            id: 1
            name: "v2ex"
        },
        ...
    ]
}

```

2\. v1/types/{id}/infos

Method: GET

Data Type: JSON

Parameters:

| Name | Required | Data Type | Description |
| ---- | -------- | --------- | ----------- |
| type | not      | int       | info type   |

Result:

```json
{
    ret_code: 0,
    ret_msg: "success",
    data: [
        {
            id: 1,
            title: "",
            url: ""
        },
        ...
    ]
}
```

### 3. Code Implementation

#### 3.1 Implementation Backend

#### 3.2 Implementation Frontend

### 4. Deployment & Test

### 5. Optimization Function



--END--